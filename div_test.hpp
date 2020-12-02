#include "gtest/gtest.h"
#include "lab4/base.hpp"
#include "lab4/Div.hpp"
#include "iterator.hpp"

TEST(DivBinaryIteratorTest, getLeft) {
    Base* twenty = new Op(20);
    Base* five = new Op(5);
    Div* four = new Div(twenty, five);
    EXPECT_EQ(four->get_left()->stringify(), "20.000000");
}

TEST(DivBinaryIteratorTest, getRight) {
    Base* twenty = new Op(20);
    Base* five = new Op(5);
    Div* four = new Div(twenty, five);
    EXPECT_EQ(four->get_right()->stringify(), "5.000000");
}

TEST(DivBinaryIteratorTest, TwoOperands) {
    Base* twenty = new Op(20);
    Base* five = new Op(5);
    Div* four = new Div(twenty, five);

    Iterator* myI = four->create_iterator();
    bool check1 = false, check2 = false;
    for(myI->first(); !myI->is_done(); myI->next()) {
        if (myI->current() == four->get_left()) {
            check1 = true;
        } else if (myI->current() == four->get_right()) {
            check2 = true;
        }
    }
    EXPECT_EQ(check1, true);
    EXPECT_EQ(check2, true);
}

TEST(DivBinaryIteratorTest, TwoNegOperands) {
    Base* twenty = new Op(20);
    Base* five = new Op(-5);
    Div* four = new Div(twenty, five);

    Iterator* myI = four->create_iterator();
    bool check1 = false, check2 = false;
    for(myI->first(); !myI->is_done(); myI->next()) {
        if (myI->current() == four->get_left()) {
            check1 = true;
        } else if (myI->current() == four->get_right()) {
            check2 = true;
        }
    }
    EXPECT_EQ(check1, true);
    EXPECT_EQ(check2, true);
}