#include "lab5_1.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    double rez = prog(A, B);
    cout << "rez = " << rez << endl;
    return 0;
}