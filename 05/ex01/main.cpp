#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Form f1("Form1", 1, 1);
        Bureaucrat b1("Bureaucrat1", 1);
        std::cout << f1 << std::endl;
        std::cout << b1 << std::endl;
        b1.signForm(f1);
        std::cout << f1 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}