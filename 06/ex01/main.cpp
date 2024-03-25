#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;
    data.s1 = "Hello";
    data.n = 42;
    data.s2 = "World";
    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);
    std::cout << ptr->s1 << " " << ptr->n << " " << ptr->s2 << std::endl;
    return 0;
}