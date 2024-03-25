#include "Base.hpp"
#include <random>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
    std::cout << "Base destroyed" << std::endl;
}

Base * generate(void) {
    //generate a random number between 0 and 2
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Define the distribution
    std::uniform_int_distribution<int> distribution(0, 2);
    
    // Generate a random number
    int random = distribution(gen);
    if (random == 0) {
        return new A();
    } else if (random == 1) {
        return new B();
    } else {
        return new C();
    }
}

void identify(Base * p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown" << std::endl;
    }
}

void identify(Base & p) {
    //function withoout pointers
    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    } catch (std::bad_cast &bc) {
        try {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        } catch (std::bad_cast &bc) {
            try {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            } catch (std::bad_cast &bc) {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}
