#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    Animal** animals = new Animal*[4];
    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }
    for (int i = 0; i < 4; i++) {
        animals[i]->makeSound();
    }
    for (int i = 0; i < 4; i++) {
        delete animals[i];
    }
    delete[] animals;
}