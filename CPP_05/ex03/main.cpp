#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <exception>

int main()
{
    try {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        delete rrf;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 1;
}
