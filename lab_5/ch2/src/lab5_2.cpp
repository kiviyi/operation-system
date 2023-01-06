#include <bits/stdc++.h>
#include "../include/math1.h"
#include <dlfcn.h>
#include "../include/math2.h"
#include "../include/lab5_2.h"
#include <vector>
#include <iostream>
// #include "version.h"
using namespace std;

double prog2(vector<int> argv){
    int argc = argv.size();
    if (argc == 1){
        perror("INCORRECT INPUT KEYS (need more arguments)\n");
        exit(0);
    } else {
        if (argv[0] == 1) {
            void * lib;
            lib = dlopen("./liblib1.so", RTLD_LAZY);
            // cout << "lib open" << endl;
            if (!lib) {
                perror("cannot open library liblib1\n");
                exit(0);
            }
            int glob = 1;
            double (*fun)(int A, int B);
            fun = (double (*)(int,int))dlsym(lib, "PrimeCount1");
            if(fun == NULL) cout << "ERROR: GG!" << endl;
            // cout << "lib podkl" << endl;
            double rez = fun(argv[1], argv[2]);
            // cout << "pered dlcolse" << endl;
            dlclose(lib);
            // cout << "pered return" << endl;
            // cout << rez << endl;
            return rez;
            
        } else if (argv[0] == 2) {
            void * lib;
            lib = dlopen("./liblib2.so", RTLD_LAZY);
            if (!lib) {
                perror("cannot open library liblib2\n");
                exit(0);
            }
            int glob = 1;
            double (*fun)(int n);
            fun = (double (*)(int))dlsym(lib, "Pi1");
            double rez = fun(argv[1]);
            rez *= 100000;
            dlclose(lib);
            int rezint = rez;
            double rezi = rezint/100000.0;
            return rezi;
        }
        return 0;
    }
}
