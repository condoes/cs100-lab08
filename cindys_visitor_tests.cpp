#include "gtest/gtest.h"

#include "lab4/add.hpp"
#include "lab4/sub.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

TEST(VisitorTest, AddVisitor) {
    Base* three = new Op(3);
    Base* five = new Op(5);
    Add* temp = new Add(three, five);
    Base* dummy = new Add(temp, five);

    Iterator *it = new PreorderIterator(dummy);

    CountVisitor *visit = new CountVisitor();
    it->first();
    while(!it->is_done()) {
        Base* phase = it->current();
        phase->accept(visit);
        it->next();
    }

    EXPECT_EQ(visit->op_count(), 3);
    EXPECT_EQ(visit->add_count(), 1);
}

TEST(VisitorTest, SubVisitor) {
    Base* three = new Op(3);
    Base* five = new Op(5);
    Sub* temp = new Sub(three, five);
    Base* dummy = new Add(temp, five);

    Iterator *it = new PreorderIterator(dummy);

    CountVisitor *visit = new CountVisitor();
    it->first();
    while(!it->is_done()) {
        Base* phase = it->current();
        phase->accept(visit);
        it->next();
    }

    EXPECT_EQ(visit->op_count(), 3);
    EXPECT_EQ(visit->sub_count(), 1);
}

TEST(VisitorTest, OpVisitor) {
    Base* three = new Op(3);
    Base* five = new Op(5);
    Base* dummy = new Add(three, five);

    CountVisitor *visit = new CountVisitor();
    Iterator *it = new PreorderIterator(dummy);
    it->first();
    while(!it->is_done()) {
        Base* phase = it->current();
        phase->accept(visit);
        it->next();
    }

    EXPECT_EQ(visit->op_count(), 2);
    EXPECT_EQ(visit->sub_count(), 0);
    EXPECT_EQ(visit->add_count(), 0);
}

TEST(VisitorTest, SubandAddVisitor) {
    Base* three = new Op(3);
    Base* five = new Op(5);
    Add* eight = new Add(three, five);
    Base* two = new Op(2);
    Sub* temp = new Sub(eight, two);
    Base* dummy = new Add(temp, two);

    Iterator *it = new PreorderIterator(dummy);

    CountVisitor *visit = new CountVisitor();
    it->first();
    while(!it->is_done()) {
        Base* phase = it->current();
        phase->accept(visit);
        it->next();
    }

    EXPECT_EQ(visit->op_count(), 4);
    EXPECT_EQ(visit->sub_count(), 1);
    EXPECT_EQ(visit->add_count(), 1);
}

TEST(VisitorTest, longVisitor) {
    Base* three = new Op(3);
    Base* five = new Op(5);
    Add* eight = new Add(three, five);
    Base* two = new Op(2);
    Sub* six = new Sub(eight, two);
    Base* four = new Op(4);
    Add* ten = new Add(four, six);
    Sub* temp = new Sub(ten, four);
    Base* dummy = new Add(temp, two);

    Iterator *it = new PreorderIterator(dummy);

    CountVisitor *visit = new CountVisitor();
    it->first();
    while(!it->is_done()) {
        Base* phase = it->current();
        phase->accept(visit);
        it->next();
    }

    EXPECT_EQ(visit->op_count(), 6);
    EXPECT_EQ(visit->sub_count(), 2);
    EXPECT_EQ(visit->add_count(), 2);
}


int main4(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

