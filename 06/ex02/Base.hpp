#pragma once
#include <string>
#include <iostream>

class Base {
    public:
        virtual ~Base();
};

Base * generate(void);
void identify(Base * p);
void identify(Base & p);