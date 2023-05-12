#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <ostream>
#include <string>


Form::Form(const std::string& n, const int g, const int e) : name(n), signe(1), grade(g), grade_exec(e)
{
    if (grade < 1 || grade_exec < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150 || grade_exec > 150)
        throw Bureaucrat::GradeTooLowException();
}

Form::Form() : name("Default"), signe(0), grade(1), grade_exec(1)
{
}

Form::~Form()
{
}

Form::Form(const Form &cp) : name(cp.getName()), signe(cp.getSigne()), grade(cp.getGrade()), grade_exec(cp.getExec())
{
}

Form &Form::operator=(const Form & cp)
{
    (void)cp;
    return *this;
}

const std::string Form::getName() const
{
    return name;
}

bool Form::getSigne() const{
    return signe;
}

int Form::getGrade() const
{
    return grade;
}

int Form::getExec() const
{
    return grade_exec;
}

std::ostream& operator<<(std::ostream& out, Form& a)
{
    out << "Name : " << a.getName() << "\nSigne : " << a.getSigne()
    << "\nGrade : " << a.getGrade() << "\nExec_Grade : "  << a.getExec();
    return out;
}
