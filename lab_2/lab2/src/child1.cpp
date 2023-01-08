#include<unistd.h>
#include <ctype.h>
#include <stdlib.h> 
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    char c[100];
    int n;
    while(n=read(0, &c, 100)) {
        for (int i = 0; i < n; ++i) {
            if (c[i] != '\n' && c[i] != '\0') {
                c[i] = tolower(c[i]);
            } else {
                break;
            }
        }
        
        write(1, &c, n);
        exit(0);
    }
    return 0;
}
