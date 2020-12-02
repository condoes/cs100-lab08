#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include "op.hpp"
#include <string>

class Add : public Base{
    private: 
        Base* firstVal; 
        Base* secondVal;
    public:
        Add(Base* value1, Base* value2) : Base() { 
            firstVal = value1;
            secondVal = value2; 
        }
        double evaluate() { return firstVal->evaluate()+secondVal->evaluate(); }
        std::string stringify() { 
            std::string str = firstVal->stringify() + " + " + secondVal->stringify();
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

#endif //__ADD_HPP__