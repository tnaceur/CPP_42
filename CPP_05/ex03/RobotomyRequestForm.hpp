#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    std::string target;
    public:
        RobotomyRequestForm (const std::string&);
        RobotomyRequestForm ();
        ~RobotomyRequestForm ();
        RobotomyRequestForm (const RobotomyRequestForm&);
        RobotomyRequestForm &operator=(const RobotomyRequestForm&);
        void execute(Bureaucrat const &) const;
};

#endif