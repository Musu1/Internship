//Test to divide two positive numbers
TEST(DivideTwoNumber, PositiveNos) {
    EXPECT_EQ(8,key.divide(16,2));
 }
//Test to divide two negative numbers 
TEST(DivideTwoNumber, NegativeNos) {
    EXPECT_EQ(1,key.divide(-3,-3));
 }
//Test to divide two numbers of opposite sign 
 TEST(DivideTwoNumber, OppositeSign) {
    EXPECT_EQ(-2,key.divide(6,-3));
 }
//Test to divide two numbers out of int data type limit 
 TEST(DivideTwoNumber, NotInLimit) {
    EXPECT_EQ(1000000000000,key.divide(3000000000000,3));
 }
 //Test to divide zero to any number
TEST(DivideTwoNumber, Zerodivisioncase1) {
     EXPECT_EQ(0,key.divide(0,3));
 }
 //Test to divide a number by 0
 TEST(DivideTwoNumber, Zerodivisioncase2){
     int result=key.divide(3,0);
     EXPECT_ANY_THROW("Not defined");
 }
 //Test to division two chars
 TEST(DivideTwoNumber,chardivision) {
     char a='a';
     int result=key.divide(8,a);
     EXPECT_ANY_THROW("Can input only integer");
 }
 
//Testing the float answers
TEST(DivideTwoNumber,floatAnswers) {
     EXPECT_EQ(3.5,key.divide(7,2));
 }