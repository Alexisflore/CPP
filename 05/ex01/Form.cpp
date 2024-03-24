#include "Form.hpp"

Form::Form(std::string name, int signGrade, int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1) {
        throw Form::GradeTooHighException();
    } else if (signGrade > 150 || execGrade > 150) {
        throw Form::GradeTooLowException();
    }
    this->sign = false;
}

Form::Form(const Form &src) : name(src.name), signGrade(src.signGrade), execGrade(src.execGrade) {
    this->sign = src.sign;
}

Form::~Form() {}


std::string Form::getName() const {
    return this->name;
}

int Form::getSignGrade() const {
    return this->signGrade;
}

int Form::getExecGrade() const {
    return this->execGrade;
}

bool Form::isSigned() const {
    return this->sign;
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
    if (this->sign) {
        throw Form::FormAlreadySignedException();
    }
    if (bureaucrat.getGrade() > this->signGrade) {
        throw Form::GradeTooLowException();
    }
    this->sign = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << form.getName() << ", form sign grade " << form.getSignGrade() << ", form exec grade " << form.getExecGrade() << ", form is signed: " << form.isSigned();
    return out;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char *Form::FormAlreadySignedException::what() const throw() {
    return "Form already signed";
}