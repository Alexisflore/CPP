#include "Animal.hpp"

Animal::Animal() : type("Animal") {}

Animal::Animal(const Animal &other) {
    *this = other;
}

Animal::~Animal() {
    std::cout << "Animal destructor" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    this->type = other.type;
    return *this;
}

std::string Animal::getType() const {
    return this->type;
}

void Animal::setType(std::string type) {
    this->type = type;
}

// void Animal::makeSound() const {
//     std::cout << "Animal sound" << std::endl;
// }