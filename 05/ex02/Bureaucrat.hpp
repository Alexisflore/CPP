#pragma once
#include <string>
#include "AForm.hpp"
#include <iostream>

class AForm;

class Bureaucrat {
    public:
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &form);
        class GradeTooHighException;
        class GradeTooLowException;
    private:
        std::string name;
        int grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

class Bureaucrat::GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
};


class Bureaucrat::GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
};