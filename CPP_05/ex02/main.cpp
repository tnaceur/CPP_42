#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <unistd.h>

int main()
{
    try
    {
        Bureaucrat a("a", 7);
        RobotomyRequestForm r("r");
        ShrubberyCreationForm s("s");
        PresidentialPardonForm p("p");
        a.executeForm(r);
        a.signForm(r);
        r.execute(a);
        s.beSigned(a);
        a.executeForm(s);
        p.beSigned(a);
        p.execute(a);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
