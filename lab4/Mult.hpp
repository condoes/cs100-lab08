#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include "op.hpp"
#include <string>

class Mult : public Base {
    private: 
        Base* v1;
        Base* v2;
    public:
        Mult(Base* val1, Base* val2) : Base() { 
            v1 = val1; 
            v2 = val2;
        }
        double evaluate() { return v1->evaluate() * v2->evaluate(); }
        std::string stringify() { 
            std::string myString = v1->stringify() + " * " + v2->stringify();
            return myString; 
        }
        Iterator* create_iterator() {
            return new BinaryIterator(this);
        }
        Base* get_left() {
            return v1;
        }
        Base* get_right() {
            return v2;
        }
};

#endif //__MULT_HPP__
