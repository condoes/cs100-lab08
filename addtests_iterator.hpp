#ifndef __ADDTESTS_ITERATOR_HPP__
#define __ADDTESTS_ITERATOR_HPP__

#include "gtest/gtest.h"

#include "lab4/add.hpp"
#include "iterator.hpp"

TEST(AddIterator, CheckCurrent) {
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Add* test = new Add(three,seven);
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

TEST(AddIterator, CheckLeftRight) {
    Base* four = new Op(4);
    Base* ten = new Op(10);
    Add* test = new Add(four,ten);
    
    EXPECT_EQ(test->get_left(), four);
    EXPECT_EQ(test->get_right(), ten);
}

TEST(AddIterator, CheckCurrentNegatives) {
    Base* negThree = new Op(-3);
    Base* negSeven = new Op(-7);
    Add* test = new Add(negSeven,negThree);
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