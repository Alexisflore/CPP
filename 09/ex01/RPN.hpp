#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include <array>
#include <vector>
#include <sstream>

class RPN {
    public:
        RPN(std::string const &str);
        RPN(RPN const &src);
        ~RPN();
        void display();
    private:
        std::vector<int> _array;
        std::string _str;
        void _calculate();
};