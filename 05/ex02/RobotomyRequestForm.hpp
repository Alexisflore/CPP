#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class RobotomyRequestForm : public AForm {
    public:
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &src);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
        void execute(Bureaucrat const &executor) const;
        std::string getTarget() const;
    private:
        std::string target;
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &robotomyRequestForm);

