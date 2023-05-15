#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &tr) : AForm("ShrubberyCreationForm", 145, 137), target(tr)
{
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a) : AForm(a.getName(), a.getGrade(), a.getExec())
{
    *this = a;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a)
{
    this->target = a.target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &a) const
{
    if (a.getGrade() > this->getExec())
        throw AForm::GradeTooLowException();
    else if (this->getSigne() == false)
        throw AForm::NotSigned();
    else
    {
        std::ofstream file(this->target + "_shrubbery");
        file << "       _-_" << std::endl;
        file << "    /~~   ~~\\" << std::endl;
        file << " /~~         ~~\\" << std::endl;
        file << "{               }" << std::endl;
        file << " \\  _-     -_  /" << std::endl;
        file << "   ~  \\\\ //  ~" << std::endl;
        file << "_- -   | | _- _" << std::endl;
        file << "  _ -  | |   -_" << std::endl;
        file << "      // \\\\" << std::endl;
    }
}
