#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
}

Cat::Cat(const Cat &other) {
    *this = other;
}

Cat::~Cat() {}

Cat &Cat::operator=(const Cat &other) {
    this->type = other.type;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow Meow" << std::endl;
}