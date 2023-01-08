#include <gtest/gtest.h>

#include <array>
#include <memory>
#include "../lab2/include/parent.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;


TEST(FirstLabTests, SimpleTest) {

    constexpr int inputSize = 6;
    // string input = "q";
    // string expectedOutput = "q";
    vector<string> input = {
            "qwerqwer",
            "QWERTY QWERTY",
            "QAZ     WSX",
            "UzImUmV AeZaKmI             ...",
            "2 + 2 = 4",
            "        "
    };
    vector<string> expectedOutput = {
            "qwerqwer",
            "qwerty qwerty",
            "qaz wsx",
            "uzimumv aezakmi ...",
            "2 + 2 = 4",
            " "
    };

    for (int i = 0; i < inputSize; i++) {
        string output = ParentRoutine("child1", "child2", input[i]);
        EXPECT_EQ(output, expectedOutput[i]);
    }
}