#include "lab.h"
#include <unistd.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <pthread.h>
#include <iostream>
using namespace std;

void srav(string str, string sub, int &b){
    int rez = str.find(sub);
    if(rez < str.length() && rez >= 0){
        b += 1;
    }
    
}


string NaivSearc(string str, string substr, int CountTread){
    int rez = 0;
    int plu = str.size()/substr.size();
    int actualThr = min(CountTread, plu);
    vector<thread> threads;
    threads.reserve(actualThr);
    for(int i=0; i<str.size(); i += plu){
        if(i + plu + substr.size() >= str.size()){
            threads.emplace_back(srav, str.substr(i), substr, ref(rez));
        } else {
            cout << str.substr(i, i + plu + substr.size()) << endl;
            threads.emplace_back(srav, str.substr(i, i + plu + substr.size()), substr, ref(rez));

        }
    }
    for(auto& thread : threads) {
        thread.join();
    }

    if(rez > 0){ 
        return "True";
    } else{
        return "False";
    }






    
    // return output;
}