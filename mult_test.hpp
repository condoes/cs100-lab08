#include "gtest/gtest.h"
#include "lab4/base.hpp"
#include "lab4/Mult.hpp"
#include "iterator.hpp"

TEST(MultBinaryIteratorTest, getLeft) {
    Base* three = new Op(3);
    Base* five = new Op(5);
    Mult* fifteen = new Mult(three, five);
    EXPECT_EQ(fifteen->get_left()->stringify(), "3.000000");
}

TEST(MultBinaryIteratorTest, getRight) {
    Base* three = new Op(3);
    Base* five = new Op(5);
    Mult* fifteen = new Mult(three, five);
    EXPECT_EQ(fifteen->get_right()->stringify(), "5.000000");
}

TEST(MultBinaryIteratorTest, TwoOperands) {
    Base* three = new Op(3);
    Base* five = new Op(5);
    Mult* fifteen = new Mult(three, five);

    Iterator* myI = fifteen->create_iterator();
    bool check1 = false, check2 = false;
    for(myI->first(); !myI->is_done(); myI->next()) {
        if (myI->current() == fifteen->get_left()) {
            check1 = true;
        } else if (myI->current() == fifteen->get_right()) {
            check2 = true;
        }
    }
    EXPECT_EQ(check1, true);
    EXPECT_EQ(check2, true);
}

TEST(MultBinaryIteratorTest, TwoNegOperands) {
    Base* three = new Op(-3);
    Base* five = new Op(-5);
    Mult* fifteen = new Mult(three, five);

    Iterator* myI = fifteen->create_iterator();
    bool check1 = false, check2 = false;
    for(myI->first(); !myI->is_done(); myI->next()) {
        if (myI->current() == fifteen->get_left()) {
            check1 = true;
        } else if (myI->current() == fifteen->get_right()) {
            check2 = true;
        }
    }
    EXPECT_EQ(check1, true);
    EXPECT_EQ(check2, true);
}