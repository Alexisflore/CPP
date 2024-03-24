#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    public:
        //default constructor
        Cat();
        //copy constructor
        Cat(const Cat &other);
        //destructor
        virtual ~Cat();
        //assignation operator
        Cat &operator=(const Cat &other);
        //makeSound
        virtual void makeSound() const;
    private:
        Brain *brain;
};