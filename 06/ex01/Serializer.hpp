#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>

class Data {
    public:
        std::string s1;
        int n;
        std::string s2;
};

//static class Serializer
class Serializer {
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};