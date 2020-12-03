#include <iostream>
#include "lab4/add.hpp"
#include "lab4/sub.hpp"
#include "lab4/Mult.hpp"
#include "lab4/Div.hpp"
#include "lab4/pow.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

int main() {
    Base* n1 = new Op(3);
    Base* n2 = new Op(7);
    Base* n3 = new Op(2);
    Mult* temp = new Mult(n1, n2);
    Mult* temp2 = new Mult(temp, n3);
    Add* temp3 = new Add(n2, temp);
    Sub* subtract = new Sub(n3, temp3);
    Pow* p = new Pow(n1, temp);
    Div* d = new Div(p, subtract);
    
    Base* dummy = new Add(d, n2);
    
    Iterator *it = new PreorderIterator(dummy);

    CountVisitor *visit = new CountVisitor();
    it->first();
    while(!it->is_done()) {
        std::cout << it->current()->stringify() << std::endl;
        Base* phase = it->current();
        phase->accept(visit);
        it->next();
    }

    std::cout << "Number of operands: " << visit->op_count() << std::endl;
    std::cout << "Number of *: " << visit->mult_count() << std::endl;
    std::cout << "Number of **: " << visit->pow_count() << std::endl;
    std::cout << "Number of +: " << visit->add_count() << std::endl;
    std::cout << "Number of -: " << visit->sub_count() << std::endl;
    std::cout << "Number of /: " << visit->div_count() << std::endl;

    return 0;
}