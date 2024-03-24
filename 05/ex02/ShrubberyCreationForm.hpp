#pragma once 
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
        void execute(Bureaucrat const &executor) const;
        std::string getTarget() const;
    private:
        std::string target;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &shrubberyCreationForm);

