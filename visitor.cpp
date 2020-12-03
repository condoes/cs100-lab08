#include "visitor.hpp"

void CountVisitor::visit_op() {
    ops++;
}

int CountVisitor::op_count(){
    return ops;
}

void CountVisitor::visit_add() {
    add++;
}

int CountVisitor::add_count(){
    return add;
}

void CountVisitor::visit_sub() {
    sub++;
}

int CountVisitor::sub_count(){
    return sub++;
}

void CountVisitor::visit_rand() {
    rands++;
}

int CountVisitor::rand_count() {
    return rands;
}