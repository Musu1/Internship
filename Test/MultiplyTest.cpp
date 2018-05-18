//Testing the multiplication of two positive numbers
TEST(MulTwoNumber, PositiveNos) {
    EXPECT_EQ(6,key.mul(2,3));
 }
//Testing the multiplication of two negative numbers 
TEST(MulTwoNumber, NegativeNos) {
    EXPECT_EQ(6,key.mul(-2,-3));
 }
//Testing the multiplication of two number of opposite signs 
 TEST(MulTwoNumber, OppositeSign) {
    EXPECT_EQ(-6,key.mul(2,-3));
 }
 //Testing the overflow in multiplication
 TEST(MulTwoNumber,overflow) {
    EXPECT_EQ(6000000000000,key.mul(3000000,2000000));
 }
 //Testing the multiplicatin of zero znd a number
TEST(MulTwoNumber, zeroAndaNumber) {
     EXPECT_EQ(0,key.mul(0,3)); 
 }
 // Tsting the char and a number multiplication
 TEST(MulTwoNumber,charMultiplication) {
     char a='a';
     int result=key.mul(8,a);
     EXPECT_ANY_THROW("Cannt input character");
 }