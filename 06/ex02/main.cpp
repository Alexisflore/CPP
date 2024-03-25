#include "Base.hpp"

int main() {
    Base *a = generate();
    Base *b = generate();
    Base *c = generate();
    std::cout << "Identify a:" << std::endl;
    identify(a);
    identify(*a);
    std::cout << "Identify b:" << std::endl;
    identify(b);
    identify(*b);
    std::cout << "Identify c:" << std::endl;
    identify(c);
    identify(*c);
    delete a;
    delete b;
    delete c;
    return 0;
}