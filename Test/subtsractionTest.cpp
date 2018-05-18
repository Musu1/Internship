//Testing the substraction of two positive integer
TEST(SubTwoNumber, PositiveNos) {
    cout<<"Testing the substraction of two positive Numbers"<<endl;
    EXPECT_EQ(5,key.sub(8,3));
 }
//Testing the substraction of two negative number
TEST(SubTwoNumber, NegativeNos) {
    cout<<"Testing the substraction of two Negative Numbers"<<endl;
    EXPECT_EQ(-4,key.sub(-7,-3));
 }
//Testing the substraction of two number with opposite sign 
 TEST(SubTwoNumber, OppositeSignCase1) {
    cout<<"Testing the substraction of two Number with oppsite sign"<<endl;
    EXPECT_EQ(5,key.sub(2,-3));
 }
//Testing the substraction of tw numbers with opposite sign 2 
  TEST(SubTwoNumber, OppositeSignCase2) {
    cout<<"Testing the substraction of two Number with oppsite sign"<<endl;
    EXPECT_EQ(-5,key.sub(-2,3));
 }
 
 //Testing the overflow in substraction
 TEST(SubTwoNumber, NotInLimit) {
    cout<<"Testing the overflow in substraction"<<endl;
    EXPECT_EQ(7000000000000,key.sub(10000000000000,3000000000000));
 }
//Testing the  
TEST(SubTwoNumber, ZeroSubtraction){
    cout<<"Testing the substraction of zer and a number"<<endl;
     EXPECT_EQ(-3,key.sub(0,3));
 }
 
 TEST(SubTwoNumber,charSubractin) {
     char a='a';
     cout<<"Testing the substraction of two characters"<<endl;
     EXPECT_EQ(0,key.add(8,a));
 }