#include "gtest/gtest.h"
#include "lab4/base.hpp"
#include "lab4/op.hpp"
#include "lab4/pow.hpp"
#include "lab4/add.hpp"
#include "lab4/Mult.hpp"
#include "lab4/sub.hpp"
#include "lab4/Div.hpp"
#include "iterator.hpp"

TEST(VisitorTest, PowTest) {
    Base* n1 = new Op(3);
    Base* n2 = new Op(7);
    Pow* temp = new Pow(n1, n2);
    Base* dummy = new Add(temp, n2);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visit = new CountVisitor(); 
    for (it->first(); !it->is_done(); it->next()) {
        it->current()->accept(visit);
    }

    EXPECT_EQ(visit->op_count(), 3);
    EXPECT_EQ(visit->pow_count(), 1);
    EXPECT_EQ(visit->add_count(), 0);
}

TEST(VisitorTest, MulTest) {
    Base* n1 = new Op(3);
    Base* n2 = new Op(7);
    Mult* temp = new Mult(n1, n2);
    Base* dummy = new Add(temp, n2);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visit = new CountVisitor(); 
    for (it->first(); !it->is_done(); it->next()) {
        it->current()->accept(visit);
    }

    EXPECT_EQ(visit->op_count(), 3);
    EXPECT_EQ(visit->mult_count(), 1);
    EXPECT_EQ(visit->add_count(), 0);
}

TEST(VisitorTest, DivTest) {
    Base* n1 = new Op(3);
    Base* n2 = new Op(7);
    Div* temp = new Div(n1, n2);
    Base* dummy = new Add(temp, n2);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visit = new CountVisitor(); 
    for (it->first(); !it->is_done(); it->next()) {
        it->current()->accept(visit);
    }

    EXPECT_EQ(visit->op_count(), 3);
    EXPECT_EQ(visit->div_count(), 1);
    EXPECT_EQ(visit->add_count(), 0);
}

TEST(VisitorTest, LongDivTest) {
    Base* n1 = new Op(3);
    Base* n2 = new Op(7);
    Base* n3 = new Op(2);
    Div* temp = new Div(n1, n2);
    Div* temp2 = new Div(temp, n3);
    Base* dummy = new Add(temp2, n2);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visit = new CountVisitor(); 
    for (it->first(); !it->is_done(); it->next()) {
        it->current()->accept(visit);
    }

    EXPECT_EQ(visit->op_count(), 4);
    EXPECT_EQ(visit->div_count(), 2);
    EXPECT_EQ(visit->add_count(), 0);
}

TEST(VisitorTest, LongMultTest) {
    Base* n1 = new Op(3);
    Base* n2 = new Op(7);
    Base* n3 = new Op(2);
    Mult* temp = new Mult(n1, n2);
    Mult* temp2 = new Mult(temp, n3);
    Base* dummy = new Add(temp2, n2);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visit = new CountVisitor(); 
    for (it->first(); !it->is_done(); it->next()) {
        it->current()->accept(visit);
    }

    EXPECT_EQ(visit->op_count(), 4);
    EXPECT_EQ(visit->mult_count(), 2);
    EXPECT_EQ(visit->add_count(), 0);
}

TEST(VisitorTest, LongPowTest) {
    Base* n1 = new Op(3);
    Base* n2 = new Op(7);
    Base* n3 = new Op(2);
    Pow* temp = new Pow(n1, n2);
    Pow* temp2 = new Pow(temp, n3);
    Base* dummy = new Add(temp2, n2);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visit = new CountVisitor(); 
    for (it->first(); !it->is_done(); it->next()) {
        it->current()->accept(visit);
    }

    EXPECT_EQ(visit->op_count(), 4);
    EXPECT_EQ(visit->pow_count(), 2);
    EXPECT_EQ(visit->add_count(), 0);
}

TEST(VisitorTest, MultDivPowTest) {
    Base* n1 = new Op(3);
    Base* n2 = new Op(7);
    Base* n3 = new Op(2);
    Div* temp = new Div(n1, n2);
    Mult* temp2 = new Mult(temp, n3);
    Pow* temp3 = new Pow(temp2, n3);
    Div* temp4 = new Div(temp3, n3);
    Base* dummy = new Add(temp4, n2);

    Iterator* it = new PreorderIterator(dummy);

    CountVisitor* visit = new CountVisitor(); 
    for (it->first(); !it->is_done(); it->next()) {
        it->current()->accept(visit);
    }

    EXPECT_EQ(visit->op_count(), 6);
    EXPECT_EQ(visit->div_count(), 2);
    EXPECT_EQ(visit->pow_count(), 1);
    EXPECT_EQ(visit->mult_count(), 1);
    EXPECT_EQ(visit->add_count(), 0);
}

int main3(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}