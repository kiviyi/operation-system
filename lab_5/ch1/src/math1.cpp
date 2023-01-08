#include <iostream>
#include "../include/math1.h"
using namespace std;

double PrimeCount1(int A, int B){
    int count = 0;
    for(int i = A; i <= B; i++){
        int flag = 1;
        for(int j = 2; j <i; j++){
            if(i%j == 0){
                flag = 0;
                break;
            }
        }
        count += flag;
    }
    return (double)count;
}

double PrimeCount2(int A, int B){
    int rez = 0;
    int *a = new int[B + 1];
    for (int i = 0; i < B + 1; i++) a[i] = i;
    for (int p = 2; p < B + 1; p++){
        if (a[p] != 0){
            if(a[p] >= A) rez++;
            for (int j = p*p; j < B + 1; j += p)
            a[j] = 0;
        }
    }
    return (double)rez;
}