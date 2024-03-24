#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() {
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat &other) {
    *this = other;
    this->brain = new Brain(*other.brain);
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    this->type = other.type;
    this->brain = new Brain(*other.brain);
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow Meow" << std::endl;
}