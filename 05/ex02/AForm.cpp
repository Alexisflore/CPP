#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1) {
        throw AForm::GradeTooHighException();
    } else if (signGrade > 150 || execGrade > 150) {
        throw AForm::GradeTooLowException();
    }
    this->sign = false;
}

AForm::AForm(const AForm &src) : name(src.name), signGrade(src.signGrade), execGrade(src.execGrade) {
    this->sign = src.sign;
}

AForm::~AForm() {}


std::string AForm::getName() const {
    return this->name;
}

int AForm::getSignGrade() const {
    return this->signGrade;
}

int AForm::getExecGrade() const {
    return this->execGrade;
}

bool AForm::isSigned() const {
    return this->sign;
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
    if (this->sign) {
        throw AForm::AFormAlreadySignedException();
    }
    if (bureaucrat.getGrade() > this->signGrade) {
        throw AForm::GradeTooLowException();
    }
    this->sign = true;
}

AForm &AForm::operator=(const AForm &src) {
    if (this != &src) {
        this->sign = src.sign;
    }
    return *this;
}

void AForm::executeForm(Bureaucrat const &executor) const {
    try {
        this->execute(executor);
        std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << executor.getName() << " cannot execute " << this->getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const AForm &Aform) {
    out << Aform.getName() << ", Aform sign grade " << Aform.getSignGrade() << ", Aform exec grade " << Aform.getExecGrade() << ", Aform is signed: " << Aform.isSigned() << std::endl;
    return out;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char *AForm::AFormAlreadySignedException::what() const throw() {
    return "Form already signed";
}