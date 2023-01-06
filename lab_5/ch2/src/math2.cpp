#include <iostream>
#include <cmath>
using namespace std;

extern "C" {
double Pi1(int n){
    double result = 0.0;
    for(int k = 0; k < n; k++){
        result += 4*pow(-1, k)/(2*k + 1);
    }
    return result;

}}

extern "C" {
double Pi2(int n){
    double result = 2.0;
    for(int k = 1; k < n; k++){
        result *= pow(2*k, 2)/((2*k-1)*(2*k+1));
    }
    return result;
}}