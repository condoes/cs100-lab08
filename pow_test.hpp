#include "gtest/gtest.h"
#include "lab4/base.hpp"
#include "lab4/pow.hpp"
#include "lab4/add.hpp"
#include "iterator.hpp"

TEST(PowBinaryIteratorTest, getLeft) {
    Base* two = new Op(2);
    Base* four = new Op(4);
    Pow* sixteen = new Pow(two, four);
    EXPECT_EQ(sixteen->get_left()->stringify(), "2.000000");
}

TEST(PowBinaryIteratorTest, getRight) {
    Base* two = new Op(2);
    Base* four = new Op(4);
    Pow* sixteen = new Pow(two, four);
    EXPECT_EQ(sixteen->get_right()->stringify(), "4.000000");
}

TEST(PowBinaryIteratorTest, TwoOperands) {
    Base* two = new Op(2);
    Base* four = new Op(4);
    Pow* sixteen = new Pow(two, four);

    Iterator* myI = sixteen->create_iterator();
    bool check1 = false, check2 = false;
    for(myI->first(); !myI->is_done(); myI->next()) {
        if (myI->current() == sixteen->get_left()) {
            check1 = true;
        } else if (myI->current() == sixteen->get_right()) {
            check2 = true;
        }
    }
    EXPECT_EQ(check1, true);
    EXPECT_EQ(check2, true);
}