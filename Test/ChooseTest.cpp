class Mockfunctions L public functions{
public:
    MOCK_METHOD2(add, int(int firstNumber,int secondNumber));
    MOCK_METHOD2(sub, int(int firstNumber,int secondNumber));
    MOCK_METHOD2(mul, int(int firstNumber,int secondNumber));
    MOCK_METHOD2(divide, int(int firstNumber,int secondNumber));
}

TEST(Choose,add){
    Mockfunctions mf;
    int c=8+3;
    EXPECT_CALL(mf, add(8,3)).
    .Times(1)
    .willOnce(Return c);
    
    int retvalue=choose(8,3,'+');
    EXPECT_EQ(retvalue,c);
}

TEST(Choose,sub){
    Mockfunctions mf;
    int c=83;
    EXPECT_CALL(mf, sub(8,3))
    .Times(1)
    .WillOnce(Return(c));
    
    int retvalue=choose(8,3,'-');
    EXPECT_EQ(retvalue,c);
    std::cout<<"hi"<<std::endl;
}
