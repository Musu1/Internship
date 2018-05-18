TEST(push,case1)
    push(1);
    EXPECT_EQ(1,STACK[TOP]);
}

TEST(push,case2)
    push(1);
    push(2);
    EXPECT_EQ(2,STACK[TOP]);
}

