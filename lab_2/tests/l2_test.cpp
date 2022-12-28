#include <gtest/gtest.h>

#include <array>
#include <memory>
#include "parent1.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;


TEST(FirstLabTests, SimpleTest) {

    constexpr int inputSize = 1;
    string input = "q";
    string expectedOutput = "q";

    for (int i = 0; i < inputSize; i++) {
        string output = ParentRoutine(getenv("child1"), getenv("child2"), input);
        EXPECT_EQ(output, expectedOutput);
    }
}