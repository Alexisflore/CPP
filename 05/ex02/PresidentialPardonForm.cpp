#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {
    std::cout << "PresidentialPardonForm constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), target(src.target) {
    std::cout << "PresidentialPardonForm copy constructor" << std::endl;
    this->target = src.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
    if (this != &src) {
        this->target = src.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {

    if (!this->isSigned() == false) {
        throw AForm::AFormNotSignedException();
    }
    if (executor.getGrade() > this->getExecGrade()) {
        throw Bureaucrat::GradeTooLowException();
    }
    std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
    return this->target;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &presidentialPardonForm) {
    out << "PresidentialPardonForm " << presidentialPardonForm.getName() << " is ";
    if (presidentialPardonForm.isSigned() == false) {
        out << "not ";
    }
    out << "signed and requires grade " << presidentialPardonForm.getSignGrade() << " to sign and grade " << presidentialPardonForm.getExecGrade() << " to execute." << std::endl;
    return out;
}