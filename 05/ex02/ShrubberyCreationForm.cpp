#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), target(src.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
    if (this != &src) {
        this->target = src.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

    if (this->isSigned()) {
        throw AForm::AFormAlreadySignedException();
    }
    if (executor.getGrade() > this->getExecGrade()) {
        throw Bureaucrat::GradeTooLowException();
    }
    std::ofstream file (this->target + "_shrubbery");
    if (!file.is_open()) {
        throw std::runtime_error("File could not be opened");
    }
    file << "             .        +          .      .          . " << std::endl;
    file << "      .            _        .                    . " << std::endl;
    file << "   ,              /;-._,-.____        ,-----.__ " << std::endl;
    file << "  ((        .    (_:#::_.:::. `-._   /:, /-._, `._, " << std::endl;
    file << "   `                 \\   _|`\"=:_::.`.);  \\ __/ / " << std::endl;
    file << "                       ,    `./  \\:. `.   )==-'  . " << std::endl;
    file << "     .      ., ,-=-.  ,\\, +#./`   \\:.  / /           . " << std::endl;
    file << " .           \\/:/`-' , ,\\ '` ` `   ): , /_  -o " << std::endl;
    file << "        .    /:+- - + +- : :- + + -:'  /(o-) \\)     . " << std::endl;
    file << "   .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7 " << std::endl;
    file << "    `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/ " << std::endl;
    file << "               \\:  `  X` _| _,\\/\'   .-' " << std::endl;
    file << " .               \":._:`\\____  /:'  /      .           . " << std::endl;
    file << "                     \\::.  :\\/:'  /              + " << std::endl;
    file << "    .                 `.:.  /:'  }      . " << std::endl;
    file << "            .           ):_(:;   \\           . " << std::endl;
    file << "                       /:. _/ ,  | " << std::endl;
    file << "                    . (|::.     ,`                  . " << std::endl;
    file << "      .                |::.    {\\ " << std::endl;
    file << "                       |::.\\  \\ `. " << std::endl;
    file << "                       |:::(\\    | " << std::endl;
    file << "               O       |:::/{ }  |                  (o " << std::endl;
    file << "                )  ___/#\\::`/ (O \"==._____   O, (O  /` " << std::endl;
    file << "           ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~ " << std::endl;
    file << "         ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~ " << std::endl;
    file << "   ~~~~  ~  ~          ~     ~  \\~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
    file.close();
}

std::string ShrubberyCreationForm::getTarget() const {
    return this->target;
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &shrubberyCreationForm) {
    out << shrubberyCreationForm.getName() << ", form sign grade " << shrubberyCreationForm.getSignGrade() << ", form exec grade " << shrubberyCreationForm.getExecGrade() << ", form is signed: " << shrubberyCreationForm.isSigned() << ", form target: " << shrubberyCreationForm.getTarget();
    return out;
}