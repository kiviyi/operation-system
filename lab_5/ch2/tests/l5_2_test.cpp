#include <gtest/gtest.h>

#include <array>
#include <memory>
#include "../include/lab5_2.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;


TEST(FirstLabTests, SimpleTest) {

    constexpr int inputSize = 5;
    vector<vector<int>> input = {{1,15,30}, 
                             {1,15,45}, 
                             {2,15}, 
                             {2, 89},
                             {2, 999}};
    vector<double> output = {4.0, 
                             8.0, 
                             3.20818, 
                             3.15282,
                             3.14259};

    // string input1 = "qwertrwrw    werwe r  werwerwer   wqery";
    // string input2 = "weer";
    // int thr = 1;
    // string expectedOutput = "True";

    for (int i = 0; i < inputSize; i++) {
        // for(int j = 0; j < 9; j++) {
            double outp = prog2(input[i]);
            EXPECT_EQ(outp, output[i]);
        // }
        // string output = NaivSearc(input1, input2, thr);
        // EXPECT_EQ(output, expectedOutput);
    }
}