#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include <stack>
#include <sstream>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

class RPN {
    public:
        RPN(std::string const &str);
        RPN(RPN const &src);
        ~RPN();
        void display();
    private:
        std::stack<long long> _array;
        std::string _str;
        void _calculate();
        int _result;
};
