#include "include/parent.h"
#include "include/utils.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main() {
    string input;

    string s;
    getline(cin, s);
    string output = ParentRoutine("child1", "child2", s);

    for (const auto &res : output){
        cout << res;
    }
    cout << endl;
    return 0;
}
