#include "include/lab.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <pthread.h>
using namespace std;

int main() {
    string input;

    string p;
    string s;
    int CountTread;
    getline(cin, p);
    getline(cin, s);
    cin >> CountTread;
    string output = NaivSearc(p, s, CountTread);

    for (const auto &res : output){
        cout << res;
    }
    cout << endl;
    return 0;
}
