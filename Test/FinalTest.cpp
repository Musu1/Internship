// tests.cpp
#include<iostream>
#include <../Src/Function.cpp>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
//#include <../UnitTesting/Test/additionTest.cpp>

using namespace std;
using :: testing :: Return;
 


class Mockfunctions : public functions{
public:
    MOCK_METHOD2(add, int(int firstNumber,int secondNumber));
    MOCK_METHOD2(sub, int(int firstNumber,int secondNumber));
    MOCK_METHOD2(mul, int(int firstNumber,int secondNumber));
    MOCK_METHOD2(divide, int(int firstNumber,int secondNumber));
};

TEST(Choose,add){

    Mockfunctions mf;
    int c=8+3;
    EXPECT_CALL(mf, add(8,3))
    .Times(1)
    .WillOnce(Return(11));
    std::cout<<"hjelp"<<std::endl;
    int retvalue=choose(8,3,'+');
    std::cout<<"Hey"<<std::endl;
    EXPECT_EQ(retvalue,11);
    std::cout<<"hi"<<std::endl;
}
 
TEST(Choose,sub){
    Mockfunctions mf;
    int c=8+3;
    EXPECT_CALL(mf, sub(8,3))
    .Times(1)
    .WillOnce(Return(c));
    
    int retvalue=choose(8,3,'-');
    EXPECT_EQ(retvalue,c);
    std::cout<<"hi"<<std::endl;
} 

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}