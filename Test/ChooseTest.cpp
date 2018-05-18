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
    ON_CALL(mf, add(8,3))
    .WillByDefault(Return(c));
    int retvalue=choose(8,3,'+');
    EXPECT_EQ(retvalue,c);
}
TEST(Choose,sub){
    Mockfunctions mf;
    int c=8-3;
    ON_CALL(mf, sub(8,3))
    .WillByDefault(Return(c));
    int retvalue=choose(8,3,'-');
    EXPECT_EQ(retvalue,c);
}
TEST(Choose,mul){
    Mockfunctions mf;
    int c=8*3;
    ON_CALL(mf, mul(8,3))
    .WillByDefault(Return(c));
    int retvalue=choose(8,3,'*');
    EXPECT_EQ(retvalue,c);
}
TEST(Choose,divide){
    Mockfunctions mf;
    int c=8/3;
    ON_CALL(mf, divide(8,3))
    .WillByDefault(Return(c));
    int retvalue=choose(8,3,'/');
    EXPECT_EQ(retvalue,c);
}
TEST(Choose,wrong_operator){
    Mockfunctions mf;
    int retvalue=choose(8,3,'%');
    EXPECT_ANY_THROW("Wrong character");
}
