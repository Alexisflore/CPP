#include "Brain.hpp"

Brain::Brain() {
    this->ideas = new std::string[100];
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = "";
    }
}

Brain::Brain(const Brain &other) {
    this->ideas = new std::string[100];
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
    }
}

Brain::~Brain() {
    delete[] this->ideas;
}

Brain &Brain::operator=(const Brain &other) {
    if (this == &other) {
        return *this;
    }
    delete[] this->ideas;
    this->ideas = new std::string[100];
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
    }
    return *this;
}

std::string Brain::getIdea(int index) const {
    return this->ideas[index];
}

void Brain::setIdea(int index, std::string idea) {
    this->ideas[index] = idea;
}

