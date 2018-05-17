//Test to divide two positive numbers
TEST(DivideTwoNumber, PositiveNos) {
    cout<<"Testing the division of two positive Numbers"<<endl;
    EXPECT_EQ(8,divide(16,2));
 }
//Test to divide two negative numbers 
TEST(DivideTwoNumber, NegativeNos) {
    cout<<"Testing the division of two Negative Numbers"<<endl;
    EXPECT_EQ(1,divide(-3,-3));
 }
//Test to divide two numbers of opposite sign 
 TEST(DivideTwoNumber, OppositeSign) {
    cout<<"Testing the division of two Number with oppsite sign"<<endl;
    EXPECT_EQ(-2,divide(6,-3));
 }
//Test to divide two numbers out of int data type limit 
 TEST(DivideTwoNumber, NotInLimit) {
    cout<<"Testing the overflow in division"<<endl;
    EXPECT_EQ(1000000000000,divide(3000000000000,3));
 }
 //Test to divide zero to any number
TEST(DivideTwoNumber, Zerodivisioncase1) {
     cout<<"Testing the divide of zero and a number"<<endl;
     EXPECT_EQ(0,divide(0,3));
 }
 //Test to divide a number by 0
 TEST(DivideTwoNumber, Zerodivisioncase2){
     cout<<"Testing the divisin of number and a zero"<<endl;
     EXPECT_EQ("Not defined",divide(3,0))
 }
 //Test to division two chars
 TEST(DivideTwoNumber,chardivision) {
     char a='a';
     cout<<"Testing the division of two characters"<<endl;
     EXPECT_EQ(0,divide(8,a));
 }
 
//Testing the float answers
TEST(DivideTwoNumber,floatAnswers) {
     cout<<"Testing the division about printing float answers"<<endl;
     EXPECT_EQ(3.5,divide(7,2));
 }