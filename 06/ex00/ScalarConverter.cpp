#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string input) {
    std::cout << "char: ";
    try {
        char c = std::stoi(input);
        if (c < 32 || c > 126) {
            std::cout << "Non displayable" << std::endl;
        } else {
            std::cout << "'" << c << "'" << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }

    std::cout << "int: ";
    try {
        int i = std::stoi(input);
        std::cout << i << std::endl;
    } catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }

    std::cout << "float: ";
    if (input == "nan" || input == "+inf" || input == "-inf") {
        std::cout << input << "f" << std::endl;
    }
    else if (input == "inff" || input == "-inff" || input == "nanf") {
        std::cout << input << std::endl;
    }
    else {
        try {
            float f = std::stof(input);
            std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        } catch (std::exception &e) {
            std::cout << "impossible" << std::endl;
        }
    }

    std::cout << "double: ";
    if (input == "nan" || input == "+inf" || input == "-inf") {
        std::cout << input << std::endl;
    }
    else {
        try {
            double d = std::stod(input);
            std::cout << std::fixed << std::setprecision(1) << d << std::endl;
        } catch (std::exception &e) {
            std::cout << "impossible" << std::endl;
        }
    }
}
