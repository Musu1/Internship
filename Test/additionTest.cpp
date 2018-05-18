//Test to add two positive numbers
TEST(AddTwoNumber, PositiveNos) {
    EXPECT_EQ(5,key.add(2,3));
 }
//Test to add two negative numbers 
TEST(AddTwoNumber, NegativeNos) {
    EXPECT_EQ(-5,key.add(-2,-3));
 }
//Test to add two numbers of opposite sign 
 TEST(AddTwoNumber, OppositeSign) {
    EXPECT_EQ(-1,key.add(2,-3));
 }
//Test to add two numbers out of int data type limit 
 TEST(AddTwoNumber, NotInLimit) {
    EXPECT_EQ(6000000000000,key.add(3000000000000,3000000000000));
 }
 //Test to add zero to any number
TEST(AddTwoNumber, ZeroAddition) {
     EXPECT_EQ(3,key.add(0,3));
 }
 //Test to add two chars
 TEST(AddTwoNumber,charAddition) {
     char a='a';
     int result=key.add(8,a);
     EXPECT_ANY_THROW("Can only input integer");
 }
