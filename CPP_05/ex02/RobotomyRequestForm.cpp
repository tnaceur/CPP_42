#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &tr) : AForm("RobotomyRequestForm", 72, 45), target(tr)
{
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &a) : AForm(a.getName(), a.getGrade(), a.getExec())
{
    *this = a;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &a)
{
    this->target = a.target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &a) const
{
    if (this->getSigne() == false)
        throw AForm::NotSigned();
    if (a.getGrade() > this->getExec())
        throw AForm::GradeTooLowException();
    std::cout << " < drdrdrdrdrdrdrdrdr > " << std::endl;
    srand(time(NULL));
    int i = rand() % 2;
    if (i)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << target << " has failed" << std::endl;
}