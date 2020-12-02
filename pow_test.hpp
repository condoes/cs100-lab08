#include "gtest/gtest.h"
#include "lab04/base.hpp"
#include "lab04/pow.hpp"
#include "lab04/add.hpp"
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
    Base* dummy = new Add(sixteen, four);

    Iterator* myI = dummy->create_iterator();
    bool check1 = false, check2 = false;
    for(myI->first(); !myI->is_done(); myI->next()) {
        if (myI->current()->stringify() == sixteen->stringify()) {
            check1 = true;
        } else if (myI->current() == sixteen->get_right()) {
            check2 = true;
        }
        //std::cout << myI->current()->stringify() << std::endl;
    }
    EXPECT_EQ(check1, true);
    EXPECT_EQ(check2, true);
}