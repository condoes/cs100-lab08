#include "visitor.hpp"

void CountVisitor::visit_mult() {
    mults++;
}

int CountVisitor::mult_count() {
    return mults;
}

void CountVisitor::visit_div() {
    divs++;
}

int CountVisitor::div_count() {
    return divs;
}

void CountVisitor::visit_pow() {
    pow++;
}

int CountVisitor::pow_count() {
    return pow;
}