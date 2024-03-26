#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include <array>
#include <vector>
#include <sstream>

class PmergeMe {
    public:
        PmergeMe(std::string const &str);
        PmergeMe(PmergeMe const &src);
        ~PmergeMe();
        void display();
    private:
        std::vector<int> _array;
        std::string _str;
        void _calculate();
};