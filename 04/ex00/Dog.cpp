#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
}

Dog::Dog(const Dog &other) {
    *this = other;
}

Dog::~Dog() {}

Dog &Dog::operator=(const Dog &other) {
    this->type = other.type;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof" << std::endl;
}
