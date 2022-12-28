#include<unistd.h>
#include <string>
#include <valarray>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char c[100];
    int n;
    while(n=read(0, &c, 100)){
        int j = 0;
        char lch = '\0';
        for (int i = 0; i < n; i++){
            if (lch != ' ' || c[i] != ' '){
                c[j] = c[i];
                j++;
            }
            lch = c[i];
        }
        for (int i = 0; i < j; i++) {
            cout << c[i];
        }
        cout << '\n';
    }
    return 0;
}