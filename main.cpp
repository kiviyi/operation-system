#include "parent.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    char c[100];
    fgets(c,sizeof(c),stdin);
    string outpu;
    outpu = par(c);
    // while(fgets(c,sizeof(c),stdin)) {
    //     int n = strlen(c);
    //     write(fd1[1], &c, n*sizeof(char));
    //     int n1= read(fd3[0], &c, n*sizeof(char));
    //     write(1,&c,n1);
    //     exit(0);
    // }
    // for (const auto &res : output){
    //     std::cout << res << std::endl;
    // }
    for (int i = 0; i < outpu.size(); i++) {
            cout << c[i];
    }
    cout << '\n';
    return 0;
    // while() {
    //     int n = strlen(c);
    //     write(fd1[1], &c, n*sizeof(char));
    //     int n1= read(fd3[0], &c, n*sizeof(char));
    //     write(1,&c,n1);
    // }
}