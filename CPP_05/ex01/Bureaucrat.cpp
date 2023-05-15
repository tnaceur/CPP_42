#include "Bureaucrat.hpp"

/* ********************************* Constructor ********************************* */

Bureaucrat::Bureaucrat(const std::string n, int g) : name(n) , grade(g)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade <= 0)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat() : name("") , grade(1) {}

Bureaucrat::Bureaucrat(const Bureaucrat& a) : name(a.getName())
{
    *this = a;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& a)
{
    this->grade = a.getGrade();
    return *this;
}

/* ************************************************************** */
void    Bureaucrat::decrement()
{
    grade++;
    if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
}

void    Bureaucrat::increment()
{
    grade--;
    if (grade <= 0)
        throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "To High grade";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "To Low grade";
}



int Bureaucrat::getGrade() const
{
    return grade;
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

void    Bureaucrat::signForm(Form& a)
{
    if (a.getGrade() >= grade)
    {
        a.setSign(true);
        std::cout << name << " signed " << a.getName() << std::endl;
    }
    else
        std::cout << name << " couldn't sign " << a.getName() << " because the Form grade is High" << std::endl;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat& a)
{
    out << a.getName() << " , bureaucrat grade " << a.getGrade();
    return out;
}

