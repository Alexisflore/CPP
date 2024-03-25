#include "easyfind.hpp"
#include <vector>
#include <iostream>

#include <iostream> // Include the necessary header file

int main() {
    std::vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    std::cout << *easyfind(v, 5) << std::endl;
    try {
        std::cout << *easyfind(v, 10) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}