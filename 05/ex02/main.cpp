#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    try {
        Bureaucrat b1("Bureaucrat1", 1);
        ShrubberyCreationForm scf1("target");
        scf1.execute(b1);
        std::cout << scf1.getTarget() << std::endl;
        PresidentialPardonForm ppf1("target");
        ppf1.execute(b1);
        std::cout << ppf1.getTarget() << std::endl;
        RobotomyRequestForm rrf1("target");
        rrf1.execute(b1);
}
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}