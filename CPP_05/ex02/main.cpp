#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <unistd.h>

int main()
{
    // Bureaucrat a("a", 1);
    // Bureaucrat b("b", 150);
    // ShrubberyCreationForm s("home");
    // PresidentialPardonForm p("home");
    // RobotomyRequestForm r("home");

    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << s << std::endl;
    // std::cout << p << std::endl;
    // std::cout << r << std::endl;

    try
    {
        Bureaucrat a("a", 1);
        RobotomyRequestForm r("home");
        a.signForm(r);
        r.execute(a);
        sleep(1);
        r.execute(a);
    //     a.signForm(s);
    //     a.executeForm(s);
    //     a.signForm(p);
    //     a.executeForm(p);
    //     a.signForm(r);
    //     a.executeForm(r);
    //     b.signForm(s);
    //     b.executeForm(s);
    //     b.signForm(p);
    //     b.executeForm(p);
    //     b.signForm(r);
    //     b.executeForm(r);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
