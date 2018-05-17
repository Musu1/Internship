TEST(SubTwoNumber, PositiveNos) {
    cout<<"Testing the substraction of two positive Numbers"<<endl;
    EXPECT_EQ(5,sub(8,3));
 }
 
TEST(SubTwoNumber, NegativeNos) {
    cout<<"Testing the substraction of two Negative Numbers"<<endl;
    EXPECT_EQ(-4,sub(-7,-3));
 }
 
 TEST(SubTwoNumber, OppositeSignCase1) {
    cout<<"Testing the substraction of two Number with oppsite sign"<<endl;
    EXPECT_EQ(5,sub(2,-3));
 }
 
  TEST(SubTwoNumber, OppositeSignCase2) {
    cout<<"Testing the substraction of two Number with oppsite sign"<<endl;
    EXPECT_EQ(-5,sub(-2,3));
 }
 
 
 TEST(SubTwoNumber, NotInLimit) {
    cout<<"Testing the overflow in substraction"<<endl;
    EXPECT_EQ(7000000000000,sub(10000000000000,3000000000000));
 }
 
TEST(SubTwoNumber, ZeroSubtraction){
    cout<<"Testing the substraction of zer and a number"<<endl;
     EXPECT_EQ(-3,sub(0,3));
 }
 
 TEST(SubTwoNumber,charSubractin) {
     char a='a';
     cout<<"Testing the substraction of two characters"<<endl;
     EXPECT_EQ(0,add(8,a));
 }