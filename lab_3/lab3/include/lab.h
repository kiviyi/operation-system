#ifndef LAB2_PARENT_H
#define LAB2_PARENT_H

#include <sys/wait.h>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <vector>
#include <string>
#include <pthread.h>

// std::string ParentRoutine(char const *pathToChild1, char const *pathToChild2,
//                                        const std::string &input);

std::string NaivSearc(std::string substr, std::string str, int CountTread);

#endif //LAB2_PARENT_H
