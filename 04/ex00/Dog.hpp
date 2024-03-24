#include "Animal.hpp"

class Dog : public Animal {
    public:
        //default constructor
        Dog();
        //copy constructor
        Dog(const Dog &other);
        //destructor
        virtual ~Dog();
        //assignation operator
        Dog &operator=(const Dog &other);
        //makeSound
        virtual void makeSound() const;
};
