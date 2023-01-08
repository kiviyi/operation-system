#include <gtest/gtest.h>

#include <array>
#include <memory>
#include <parent.h>
#include <vector>
using namespace std;


TEST(FourLabTests, SimpleTest) {

    constexpr int inputSize = 2;

    array< vector<string>, inputSize> input;
    input[0] = {
            "qwerqwer",
            "QWERTY QWERTY",
            "QAZ     WSX",
            "UzImUmV AeZaKmI             ...",
            "2 + 2 = 4"
    };
    input[1] = {
            "        "
    };

    array< vector<string>, inputSize> expectedOutput;
    expectedOutput[0] = {
            "qwerqwer",
            "qwerty qwerty",
            "qaz wsx",
            "uzimumv aezakmi ...",
            "2 + 2 = 4"
    };
    expectedOutput[1] = {
            " "
    };


    for (int i = 0; i < inputSize; i++) {
        auto result = ParentRoutine(input[i]);
        EXPECT_EQ(result, expectedOutput[i]);
    }
}