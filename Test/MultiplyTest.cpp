//Testing the multiplication of two positive numbers
TEST(MulTwoNumber, PositiveNos) {
    cout<<"Testing the multiplication of two positive Numbers"<<endl;
    EXPECT_EQ(6,mul(2,3));
 }
//Testing the multiplication of two negative numbers 
TEST(MulTwoNumber, NegativeNos) {
    cout<<"Testing the multiplication of two Negative Numbers"<<endl;
    EXPECT_EQ(6,mul(-2,-3));
 }
//Testing the multiplication of two number of opposite signs 
 TEST(MulTwoNumber, OppositeSign) {
    cout<<"Testing the multiplication of two Number with oppsite sign"<<endl;
    EXPECT_EQ(-6,mul(2,-3));
 }
 //Testing the overflow in multiplication
 TEST(MulTwoNumber,overflow) {
    cout<<"Testing the overflow in multiplication"<<endl;
    EXPECT_EQ(6000000000000,mul(3000000,2000000));
 }
 //Testing the multiplicatin of zero znd a number
TEST(MulTwoNumber, zeroAndaNumber) {
     cout<<"Testing the addition of zero and a number"<<endl;
     EXPECT_EQ(3,add(0,3));
 }
 // Tsting the char and a number multiplication
 TEST(MulTwoNumber,charMultiplication) {
     char a='a';
     cout<<"Testing the multiplication of two characters"<<endl;
     EXPECT_EQ(0,add(8,a));
 }