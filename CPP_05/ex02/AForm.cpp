#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ostream>
#include <string>


AForm::AForm(const std::string& n, const int g, const int e) : name(n), signe(false), grade(g), grade_exec(e)
{
    if (grade < 1 || grade_exec < 1)
        throw AForm::GradeTooHighException();
    if (grade > 150 || grade_exec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm() : name("Default"), signe(0), grade(1), grade_exec(1)
{
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &cp) : name(cp.getName()), signe(cp.getSigne()), grade(cp.getGrade()), grade_exec(cp.getExec())
{
}

AForm &AForm::operator=(const AForm & cp)
{
    (void)cp;
    return *this;
}

const std::string AForm::getName() const
{
    return name;
}

bool AForm::getSigne() const{
    return signe;
}

int AForm::getGrade() const
{
    return grade;
}

int AForm::getExec() const
{
    return grade_exec;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "To High grade";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "To Low grade";
}


void    AForm::beSigned(const Bureaucrat& a)
{
    if (a.getGrade() <= grade)
        signe = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, AForm& a)
{
    out << "Name : " << a.getName() << "\nSigne : " << a.getSigne()
    << "\nGrade : " << a.getGrade() << "\nExec_Grade : "  << a.getExec();
    return out;
}

const char *AForm::NotSigned::NotSigned::what() const throw()
{
    return "Form Not signed";
}
