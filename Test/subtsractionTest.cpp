//Testing the substraction of two positive integer
TEST(SubTwoNumber, PositiveNos) {
    EXPECT_EQ(5,key.sub(8,3));
 }
//Testing the substraction of two negative number
TEST(SubTwoNumber, NegativeNos) {
    EXPECT_EQ(-4,key.sub(-7,-3));
 }
//Testing the substraction of two number with opposite sign 
 TEST(SubTwoNumber, OppositeSignCase1) {
    EXPECT_EQ(5,key.sub(2,-3));
 }
//Testing the substraction of tw numbers with opposite sign 2 
  TEST(SubTwoNumber, OppositeSignCase2) {
    EXPECT_EQ(-5,key.sub(-2,3));
 }
 
 //Testing the overflow in substraction
 TEST(SubTwoNumber, NotInLimit) {
    EXPECT_EQ(7000000000000,key.sub(10000000000000,3000000000000));
 }
//Testing the  
TEST(SubTwoNumber, ZeroSubtraction){
     EXPECT_EQ(-3,key.sub(0,3));
 }
 
 TEST(SubTwoNumber,charSubractin) {
     char a='a';
     int result=key.sub(8,a);
     EXPECT_ANY_THROW("Can only input integer");
 }