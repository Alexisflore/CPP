#include "Dog.hpp"
#include <iostream>
#include "Brain.hpp"

Dog::Dog() {
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &other) {
    *this = other;
    this->brain = new Brain(*other.brain);
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
    this->type = other.type;
    this->brain = new Brain(*other.brain);
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof" << std::endl;
}
