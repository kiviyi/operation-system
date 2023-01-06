#include "../src/search.hpp"
using namespace std;
vector<unsigned int> PrefixFunction(const string & s) {
	unsigned int n = s.size();
	vector<unsigned int> p(n);
	for (unsigned int i = 1; i < n; ++i) {
		p[i] = p[i - 1];
		while (p[i] > 0 and s[i] != s[p[i]]) {
			p[i] = p[p[i] - 1];
		}
		if (s[i] == s[p[i]]) {
			++p[i];
		}
	}
	return p;
}

vector<unsigned int> KMPWeak(const string & pattern, const string & text) {
	vector<unsigned int> p = PrefixFunction(pattern);
	unsigned int m = pattern.size();
	unsigned int n = text.size();
	unsigned int i = 0;
	vector<unsigned int> ans;
	if (m > n) {
		return ans;
	}
	while (i < n - m + 1) {
		unsigned int j = 0;
		while (j < m and pattern[j] == text[i + j]) {
			++j;
		}
		if (j == m) {
			ans.push_back(i);
		} else {
			if (j > 0 and j > p[j - 1]) {
				i = i + j - p[j - 1] - 1;
			}
		}
		++i;
	}
	return ans;
}

vector<unsigned int> ZFunction(const string & s) {
	unsigned int n = s.size();
	vector<unsigned int> z(n);
	unsigned int l = 0, r = 0;
	for (unsigned int i = 1; i < n; ++i) {
		if (i <= r) {
			z[i] = min(z[i - l], r - i);
		}
		while (i + z[i] < n and s[i + z[i]] == s[z[i]]) {
			++z[i];
		}
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
	return z;
}

vector<unsigned int> StrongPrefixFunction(const string & s) {
	vector<unsigned int> z = ZFunction(s);
	unsigned int n = s.size();
	vector<unsigned int> sp(n);
	for (unsigned int i = n - 1; i > 0; --i) {
		sp[i + z[i] - 1] = z[i];
	}
	return sp;
}

vector<unsigned int> KMPStrong(const string & pattern, const string & text) {
	vector<unsigned int> p = StrongPrefixFunction(pattern);
	unsigned int m = pattern.size();
	unsigned int n = text.size();
	unsigned int i = 0;
	vector<unsigned int> ans;
	if (m > n) {
		return ans;
	}
	while (i < n - m + 1) {
		unsigned int j = 0;
		while (j < m and pattern[j] == text[i + j]) {
			++j;
		}
		if (j == m) {
			ans.push_back(i);
		} else {
			if (j > 0 and j > p[j - 1]) {
				i = i + j - p[j - 1] - 1;
			}
		}
		++i;
	}
	return ans;
}