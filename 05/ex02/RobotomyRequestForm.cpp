#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), target(src.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
    if (this != &src) {
        this->target = src.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {

    if (!this->isSigned() == false) {
        throw AForm::AFormNotSignedException();
    }
    if (executor.getGrade() > this->getExecGrade()) {
        throw Bureaucrat::GradeTooLowException();
    }
    std::cout << "*drilling noises*" << std::endl;
    if (rand() % 2) {
        std::cout << this->target << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << this->target << " robotomization failed" << std::endl;
    }
}