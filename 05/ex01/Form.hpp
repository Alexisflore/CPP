#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
    public:
        Form(std::string name, int signGrade, int execGrade);
        ~Form();
        Form(const Form &src);
        std::string getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool isSigned() const;
        void beSigned(Bureaucrat const &bureaucrat);
        class GradeTooHighException;
        class GradeTooLowException;
        class FormAlreadySignedException;
    private:
        std::string const name;
        bool sign;
        int signGrade;
        int execGrade;
};

std::ostream &operator<<(std::ostream &out, const Form &form);

class Form::GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
};

class Form::GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
};

class Form::FormAlreadySignedException : public std::exception {
    public:
        virtual const char *what() const throw();
};
