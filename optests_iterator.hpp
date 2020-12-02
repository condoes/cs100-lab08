#ifndef __OP_TESTS_ITERATOR_HPP__
#define __OP_TESTS_ITERATOR_HPP__

#include "gtest/gtest.h"

#include "lab4/op.hpp"
#include "iterator.hpp"

TEST(OpIterator, CheckCurrent) {
    Base* test = new Op(0);
    Iterator* OpIterator = test->create_iterator();
    bool check1 = false;
    if(OpIterator->current() == nullptr) {
        check1 = true;
    }
    
    EXPECT_EQ(check1, true);
}

TEST(OpIterator, CheckLeftRight) {
    Base* four = new Op(4);

    EXPECT_EQ(four->get_left(), nullptr);
    EXPECT_EQ(four->get_right(), nullptr);
}



#endif