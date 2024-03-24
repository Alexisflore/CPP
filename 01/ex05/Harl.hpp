#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Harl
{
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
    private:
        void debug();
        void info();
        void error();
        void warning();
        static std::string const mood[];
};