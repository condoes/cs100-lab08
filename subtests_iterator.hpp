#ifndef __SUBTESTS_ITERATOR_HPP__
#define __SUBTESTS_ITERATOR_HPP__

#include "gtest/gtest.h"

#include "lab4/sub.hpp"
#include "iterator.hpp"

TEST(SubIterator, CheckCurrent) {
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Sub* test = new Sub(three,seven);
    Iterator* addIterator = test->create_iterator();
    bool check1 = false, check2 = false;
    for(addIterator->first(); !addIterator->is_done(); addIterator->next()) {
        if(addIterator->current()==test->get_left()) {
            check1 = true;
        }
        else if (addIterator->current() == test->get_right()) {
            check2 = true;
        }
    }

    EXPECT_EQ(check1, true);
    EXPECT_EQ(check2, true);
}

TEST(SubIterator, CheckLeftRight) {
    Base* four = new Op(4);
    Base* ten = new Op(10);
    Sub* test = new Sub(four,ten);
    
    EXPECT_EQ(test->get_left(), four);
    EXPECT_EQ(test->get_right(), ten);
}

TEST(SubIterator, CheckCurrentNegatives) {
    Base* negThree = new Op(-3);
    Base* negSeven = new Op(-7);
    Sub* test = new Sub(negSeven,negThree);
    Iterator* addIterator = test->create_iterator();
    bool check1 = false, check2 = false;
    for(addIterator->first(); !addIterator->is_done(); addIterator->next()) {
        if(addIterator->current()==test->get_left()) {
            check1 = true;
        }
        else if (addIterator->current() == test->get_right()) {
            check2 = true;
        }
    }

    EXPECT_EQ(check1, true);
    EXPECT_EQ(check2, true);
}



#endif