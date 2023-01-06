#include <gtest/gtest.h>

#include <array>
#include <memory>
#include "../include/lab5_1.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;


TEST(FirstLabTests, SimpleTest) {

    constexpr int inputSize = 5;
    vector<int> input1 = {15, 
                             23, 
                             3, 
                             1000,
                             100000};
    vector<int> input2 = {30, 
                             45, 
                             89, 
                             2000,
                             101000};
    vector<double> output = {4.0, 
                             6.0, 
                             23.0, 
                             135.0,
                             81.0};

    // string input1 = "qwertrwrw    werwe r  werwerwer   wqery";
    // string input2 = "weer";
    // int thr = 1;
    // string expectedOutput = "True";

    for (int i = 0; i < inputSize; i++) {
        // for(int j = 0; j < 9; j++) {
            double outp = prog(input1[i], input2[i]);
            EXPECT_EQ(outp, output[i]);
        // }
        // string output = NaivSearc(input1, input2, thr);
        // EXPECT_EQ(output, expectedOutput);
    }
}