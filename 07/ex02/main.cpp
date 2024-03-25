#include "Array.hpp"

int main() {
    Array<int> intArray(5);
    Array<std::string> stringArray(5);

    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i + 1;
    }
    for (unsigned int i = 0; i < stringArray.size(); i++) {
        stringArray[i] = std::to_string(i + 1);
    }
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << std::endl;
    }
    for (unsigned int i = 0; i < stringArray.size(); i++) {
        std::cout << stringArray[i] << std::endl;
    }
    try {
        intArray[5] = 6;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}