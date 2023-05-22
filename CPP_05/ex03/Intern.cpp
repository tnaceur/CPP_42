#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>


Intern::Intern()
{
    check[0] = "robotomy request";
    check[1] = "shrubbery creation";
    check[2] = "presidential pardon";
}

Intern::Intern (const Intern& other)
{
    *this = other;
}

Intern	&Intern::operator=(const Intern& other)
{
    for (int i = 0;i < 3; i++)
        this->check[i] = other.check[i];
    return *this;
}

Intern::~Intern(void)
{
}

const char *Intern::NoForm::what() const throw()
{
    return "Form not found";
}

AForm* Intern::Robotomy(const std::string& target) const{
    return new RobotomyRequestForm(target);
}

AForm* Intern::Shrubbery(const std::string& target) const{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::Presidential(const std::string& target) const{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string& Form, const std::string& target)
{
    int     i;
    AForm* (Intern::*function[3]) (const std::string&) const = {&Intern::Robotomy, &Intern::Shrubbery, &Intern::Presidential};

    for (i = 0; i < 3; i++)
        if (check[i] == Form)
        {
            std::cout << "Intern creates " << Form << std::endl;
            return (this->*function[1])(target);
        }
    throw NoForm();
}
