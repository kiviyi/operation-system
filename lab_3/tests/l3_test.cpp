#include <gtest/gtest.h>

#include <array>
#include <memory>
#include "../lab3/include/lab.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;


TEST(FirstLabTests, SimpleTest) {

    constexpr int inputSize = 5;
    vector<string> input1 = {"qwertyuiop", 
                             "Hello world", 
                             "i live in the world", 
                             "escalibur",
                             "Once I went for a walk with him out Town Street on a Saturday afternoon. It was a warm day, and after a while I said I wanted a soda. Well, he said, he didn't care if he took something himself. We went into a drugstore, and I ordered a chocolate soda and he had a lemon phosphate. When we had finished, he said, Jimmy, my son, I'll match you to see who pays for the drinks. He handed me a quarter and he told me to toss the quarter and he would call the turn. He called heads and won. I paid for the drinks. It left me with a dime.I was fifteen when Doc got out his pamphlets, as he called them. He had eased the misery of the life of a smalltime printer and the grateful man had given him a special price on two thousand advertising pamphlets. There was very little in them about Blackhawk Liniment. They were mostly about Doc himself and his Life in the Far West. He had gone out to Franklin Park one day with a photographer — another of his numerous friends — and there the photographer took dozens of pictures of Doc, a lariat in one hand, a six-shooter in the other. I had gone along. When the pamphlets came out, there were the pictures of Doc, peering around trees, crouching behind bushes, whirling the lariat, aiming the gun. Dr. H.M. Marlowe Hunting Indians was one of the captions. Dr. H.M. Marlowe after Hoss-Thieves was another one. He was very proud of the pamphlets and always had a sheaf with him. He would pass them out to people on the street",
                             " "};
    vector<string> input2 = {"we", 
                             "ella", 
                             "in", 
                             " ",
                             "to people on"
                             "a"};
    vector<string> output = {"True", 
                             "False", 
                             "True", 
                             "False",
                             "True",
                             "False"};

    // string input1 = "qwertrwrw    werwe r  werwerwer   wqery";
    // string input2 = "weer";
    // int thr = 1;
    // string expectedOutput = "True";

    for (int i = 0; i < inputSize; i++) {
        for(int j = 1; j < 4; j++) {
            string outp = NaivSearc(input1[i], input2[i], j);
            EXPECT_EQ(outp, output[i]);
        }
        // string output = NaivSearc(input1, input2, thr);
        // EXPECT_EQ(output, expectedOutput);
    }
}