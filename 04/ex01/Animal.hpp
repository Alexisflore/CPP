#pragma once
#include <string>
#include <iostream>

class Animal {
    public:
        //default constructor
        Animal();
        //copy constructor
        Animal(const Animal &other);
        //destructor
        virtual ~Animal();
        //assignation operator
        Animal &operator=(const Animal &other);
        //getters
        std::string getType() const;
        //setters
        void setType(std::string type);
        //makeSound
        virtual void makeSound() const;
    protected:
        //implemant a string name type
        std::string type;
};