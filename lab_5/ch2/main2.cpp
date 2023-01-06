#include "lab5_2.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, A, B, k;
    double rez;
    // cin >> A >> B;
    cin >> n;
    if(n == 1){
        cin >> A >> B;
        vector<int> v = {n, A, B};
        rez = prog2(v);
    } else if(n == 2){
        cin >> k;
        vector<int> v = {n, k};
        rez = prog2(v);
    }
    cout << "rez: " << rez << endl;
}