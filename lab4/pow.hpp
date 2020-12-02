#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include "op.hpp"
#include <string>
#include <cmath>

class Pow : public Base {
    private: 
        Base* base; 
        Base* exponent;
    public:
        Pow(Base* base, Base* exp) : Base() { 
            this->base = base;
            exponent = exp; 
        }
        double evaluate() { return pow(base->evaluate(), exponent->evaluate()); }
        std::string stringify() { 
            std::string str = base->stringify() + " ** " + exponent->stringify();
            return str;
        }
        Iterator* create_iterator() {
            return new PreorderIterator(this);
        }
        Base* get_left() {
            return base;
        }
        Base* get_right() {
            return exponent;
        }
};

#endif //__ADD_HPP__