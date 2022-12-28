#include "parent.h"
#include <unistd.h>
#include "utils.h"
#include <vector>
#include <stdio.h>
using namespace std;

string ParentRoutine(char const *pathToChild1, char const *pathToChild2,
                                       const string &input){

    string output;

    int firstPipe[2];
    CreatePipe(firstPipe);
    int pipeBetweenChildren[2];
    CreatePipe(pipeBetweenChildren);

    int pid = fork();



    if (pid == 0) {

        close(firstPipe[WRITE_END]);
        close(pipeBetweenChildren[READ_END]);

        MakeDup2(firstPipe[READ_END], STDIN_FILENO);
        MakeDup2(pipeBetweenChildren[WRITE_END], STDOUT_FILENO);

        if (execl(pathToChild1, pathToChild1, NULL) == -1) {
            GetExecError(pathToChild1);
        }
        close(firstPipe[READ_END]);
        close(firstPipe[WRITE_END]);
    } else if (pid == -1) {
        GetForkError();
    } else {
        close(firstPipe[READ_END]);
        write(firstPipe[WRITE_END], input.c_str(), input.size());
        close(firstPipe[WRITE_END]);

        int secondPipe[2];
        CreatePipe(secondPipe);

        pid = fork();

        if (pid == 0) {
            close(secondPipe[READ_END]);
            close(pipeBetweenChildren[WRITE_END]);

            MakeDup2(pipeBetweenChildren[READ_END], STDIN_FILENO);
            MakeDup2(secondPipe[WRITE_END], STDOUT_FILENO);

            if (execl(pathToChild2, pathToChild2, NULL) == -1) {
                GetExecError(pathToChild2);
            }
            close(pipeBetweenChildren[READ_END]);
            close(secondPipe[WRITE_END]);
        } else if (pid == -1) {
            GetForkError();
        } else {
            close(secondPipe[WRITE_END]);
            close(pipeBetweenChildren[WRITE_END]);
            close(pipeBetweenChildren[READ_END]);

            wait(nullptr);
            char ch;

            while (read(secondPipe[READ_END], &ch, 1) && ch != '\n'){
                    output += ch;
            }
            close(secondPipe[READ_END]);
        }
    }
    return output;
}