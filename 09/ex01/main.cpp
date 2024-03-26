#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./rpn <string>" << std::endl;
        return 1;
    }
    RPN rpn(argv[1]);
    rpn.display();
    return 0;
}