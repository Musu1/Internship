// tests.cpp
#include<iostream>
#include "../Src/Function.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "additionTest.cpp"
#include "subtsractionTest.cpp"
#include "MultiplyTest.cpp"
#include "DivideTest.cpp"


using namespace std;
using :: testing :: Return;
#include "ChooseTest.cpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}