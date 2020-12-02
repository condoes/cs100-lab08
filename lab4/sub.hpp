#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "op.hpp"
#include "../iterator.hpp"
#include <string>

class Sub : public Base {
    private: 
        Base* firstVal; 
        Base* secondVal;
    public:
        Sub(Base* value1, Base* value2) : Base() { 
            firstVal = value1;
            secondVal = value2; 
        }
        double evaluate() { return firstVal->evaluate() - secondVal->evaluate(); }
        std::string stringify() { 
            std::string str = firstVal->stringify() + " - " + secondVal->stringify();
            return str;
        }
        
        Iterator* create_iterator() {
            return new BinaryIterator(this);
        }

        Base* get_right() {
            return secondVal;
        }

        Base* get_left() {
            return firstVal;
        }
        
};

#endif //__SUB_HPP__