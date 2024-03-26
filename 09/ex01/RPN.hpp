#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include <stack>
#include <sstream>

class RPN {
    public:
        RPN(std::string const &str);
        RPN(RPN const &src);
        ~RPN();
        void display();
    private:
        std::stack<int> _array;
        std::string _str;
        void _calculate();
        int _result;
};