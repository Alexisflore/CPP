#include "iter.hpp"
#include <iostream>
#include <string>
#include <cstddef>
#include <cstdlib>

void print1(int const &i) {
    std::cout << i << std::endl;
}

void print2(std::string const &s) {
    std::cout << s << std::endl;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::string stringArray[] = {"one", "two", "three", "four", "five"};

    iter(intArray, 5, print1);
    iter(stringArray, 5, print2);
    return 0;
}