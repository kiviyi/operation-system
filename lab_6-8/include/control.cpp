#include <unistd.h>
#include <vector>

#include "../src/topology.hpp"
#include "../src/zmq_std.hpp"
using namespace std;
using node_id_type = long long;

int main() {
	int rc;
	topology_t<node_id_type> control_node;
	vector< pair<void*, void*> > childs;

	string s;
	node_id_type id;
	while (cin >> s >> id) {
		if (s == "create") {
			node_id_type parent_id;
			cin >> parent_id;
			if (parent_id == -1) {
				void* new_context = NULL;
				void* new_socket = NULL;
				zmq_init_pair_socket(new_context, new_socket);
				rc = zmq_bind(new_socket, ("tcp://*:" + to_string(PORT_BASE + id)).c_str());
				assert(rc == 0);

				int fork_id = fork();
				if (fork_id == 0) {
					rc = execl(NODE_EXECUTABLE_NAME, NODE_EXECUTABLE_NAME, to_string(id).c_str(), NULL);
					assert(rc != -1);
					return 0;
				} else {
					bool ok = true;
					node_token_t reply_info({fail, id, id});
					ok = zmq_recieve_msg_wait(reply_info, new_socket);

					node_token_t* token = new node_token_t({ping, id, id});
					node_token_t reply({fail, id, id});
					ok = zmq_send_recieve_wait(token, reply, new_socket);
					if (ok and reply.action == success) {
						childs.push_back(make_pair(new_context, new_socket));
						control_node.insert(id);
						cout << "OK: " << reply_info.id << endl;
					} else {
						rc = zmq_close(new_socket);
						assert(rc == 0);
						rc = zmq_ctx_term(new_context);
						assert(rc == 0);
					}
				}
			} else if (control_node.find(parent_id) == -1) {
				cout << "Error: Not found" << endl;
			} else {
				if (control_node.find(id) != -1) {
					cout << "Error: Already exists" << endl;
				} else {
					int ind = control_node.find(parent_id);
					node_token_t* token = new node_token_t({create, parent_id, id});
					node_token_t reply({fail, id, id});
					if (zmq_send_recieve_wait(token, reply, childs[ind].second) and reply.action == success) {
						cout << "OK: " << reply.id << endl;
						control_node.insert(parent_id, id);
					} else {
						cout << "Error: Parent is unavailable" << endl;
					}
				}
			}
		} else if (s == "remove") {
			int ind = control_node.find(id);
			if (ind != -1) {
				node_token_t* token = new node_token_t({destroy, id, id});
				node_token_t reply({fail, id, id});
				bool ok = zmq_send_recieve_wait(token, reply, childs[ind].second);
				if (reply.action == destroy and reply.parent_id == id) {
					rc = zmq_close(childs[ind].second);
					assert(rc == 0);
					rc = zmq_ctx_term(childs[ind].first);
					assert(rc == 0);
					vector< pair<void*, void*> >::iterator it = childs.begin();
					while (ind--) {
						++it;
					}
					childs.erase(it);
				} else if (reply.action == bind and reply.parent_id == id) {
					rc = zmq_close(childs[ind].second);
					assert(rc == 0);
					rc = zmq_ctx_term(childs[ind].first);
					assert(rc == 0);
					zmq_init_pair_socket(childs[ind].first, childs[ind].second);
					rc = zmq_bind(childs[ind].second, ("tcp://*:" + to_string(PORT_BASE + reply.id)).c_str());
					assert(rc == 0);
				}
				if (ok) {
					control_node.erase(id);
					cout << "OK" << endl;
				} else {
					cout << "Error: Node is unavailable" << endl;
				}
			} else {
				cout << "Error: Not found" << endl;
			}
		} else if (s == "ping") {
			int ind = control_node.find(id);
			if (ind != -1) {
				node_token_t* token = new node_token_t({ping, id, id});
				node_token_t reply({fail, id, id});
				if (zmq_send_recieve_wait(token, reply, childs[ind].second) and reply.action == success) {
					cout << "OK: 1" << endl;
				} else {
					cout << "OK: 0" << endl;
				}
			} else {
				cout << "Error: Not found" << endl;
			}
		} else if (s == "back") {
			int ind = control_node.find(id);
			if (ind != -1) {
				node_token_t* token = new node_token_t({back, id, id});
				node_token_t reply({fail, id, id});
				if (zmq_send_recieve_wait(token, reply, childs[ind].second)) {
					if (reply.action == success) {
						node_token_t* token_back = new node_token_t({back, id, id});
						node_token_t reply_back({fail, id, id});
						vector<unsigned int> calculated;
						while (zmq_send_recieve_wait(token_back, reply_back, childs[ind].second) and reply_back.action == success) {
							calculated.push_back(reply_back.id);
						}
						if (calculated.empty()) {
							cout << "OK: " << reply.id << " : -1" << endl;
						} else {
							cout << "OK: " << reply.id << " : ";
							for (size_t i = 0; i < calculated.size() - 1; ++i) {
								cout << calculated[i] << ", ";
							}
							cout << calculated.back() << endl;
						}
					} else {
						cout << "Error: No calculations to back" << endl;
					}
				} else {
					cout << "Error: Node is unavailable" << endl;
				}
			} else {
				cout << "Error: Not found" << endl;
			}
		} else if (s == "exec") {
			string pattern, text;
			cin >> pattern >> text;
			int ind = control_node.find(id);
			if (ind != -1) {
				bool ok = true;
				string text_pattern = pattern + SENTINEL + text + SENTINEL;
				for (size_t i = 0; i < text_pattern.size(); ++i) {
					node_token_t* token = new node_token_t({exec, text_pattern[i], id});
					node_token_t reply({fail, id, id});
					if (!zmq_send_recieve_wait(token, reply, childs[ind].second) or reply.action != success) {
						ok = false;
						break;
					}
				}
				if (ok) {
					cout << "OK" << endl;
				} else {
					cout << "Error: Node is unavailable" << endl;
				}
			} else {
				cout << "Error: Not found" << endl;
			}
		}
	}

	for (size_t i = 0; i < childs.size(); ++i) {
		rc = zmq_close(childs[i].second);
		assert(rc == 0);
		rc = zmq_ctx_term(childs[i].first);
		assert(rc == 0);
	}
}