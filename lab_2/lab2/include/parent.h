#ifndef LAB2_PARENT_H
#define LAB2_PARENT_H

#include <sys/wait.h>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <vector>

std::string ParentRoutine(char const *pathToChild1, char const *pathToChild2,
                                       const std::string &input);

#endif //LAB2_PARENT_H
