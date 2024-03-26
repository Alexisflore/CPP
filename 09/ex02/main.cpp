#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    try {
        PmergeMe pmergeme(argc, argv);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}