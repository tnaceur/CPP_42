#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &tr) : AForm("PresidentialPardonForm", 25, 5), target(tr)
{
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &a) : AForm(a.getName(), a.getGrade(), a.getExec())
{
    *this = a;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &a)
{
    this->target = a.target;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &a) const
{
    if (this->getSigne() == false)
        throw AForm::NotSigned();
    if (a.getGrade() > this->getExec())
        throw AForm::GradeTooLowException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
