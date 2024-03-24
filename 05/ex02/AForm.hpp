#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"



class Bureaucrat;

//abstract class
class AForm {
    public:
        AForm(std::string name, int signGrade, int execGrade);
        virtual ~AForm();
        AForm(const AForm &src);
        AForm &operator=(const AForm &src);
        std::string getName() const;
        bool isSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSigned(Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;
        class GradeTooHighException;
        class GradeTooLowException;
        class AFormAlreadySignedException;
        class AFormNotSignedException;
    private:
        const std::string name;
        bool sign;
        const int signGrade;
        const int execGrade;
};

std::ostream &operator<<(std::ostream &out, const AForm &aform);

class AForm::GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
};

class AForm::GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
};

class AForm::AFormAlreadySignedException : public std::exception {
    public:
        virtual const char *what() const throw();
};

class AForm::AFormNotSignedException : public std::exception {
    public:
        virtual const char *what() const throw();
};