#pragma once
#include <string>
#include <iostream>

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
    private:
        std::string name;
        class GradeTooHighException;
        class GradeTooLowException;
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
