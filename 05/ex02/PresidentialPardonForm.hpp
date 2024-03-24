#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &src);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
        void execute(Bureaucrat const &executor) const;
        std::string getTarget() const;
    private:
        std::string target;
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &presidentialPardonForm);

