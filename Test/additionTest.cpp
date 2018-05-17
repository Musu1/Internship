TEST(AddTwoNumber, PositiveNos) {
    cout<<"Testing the addition of two positive Numbers"<<endl;
    EXPECT_EQ(5,add(2,3));
 }
 
TEST(AddTwoNumber, NegativeNos) {
    cout<<"Testing the addition of two Negative Numbers"<<endl;
    EXPECT_EQ(-5,add(-2,-3));
 }
 
 TEST(AddTwoNumber, OppositeSign) {
    cout<<"Testing the addition of two Number with oppsite sign"<<endl;
    EXPECT_EQ(-1,add(2,-3));
 }
 
 TEST(AddTwoNumber, NotInLimit) {
    cout<<"Testing the overflow in addition"<<endl;
    EXPECT_EQ(6000000000000,add(3000000000000,3000000000000));
 }
 
TEST(AddTwoNumber, ZeroAddition) {
     cout<<"Testing the addition of zer and a number"<<endl;
     EXPECT_EQ(3,add(0,3));
 }
 
 TEST(AddTwoNumber,charAddition) {
     cout<<"Testing the addition of two characters"<<endl;
     EXPECT_EQ("wrong data type",add(a,b));
 }

