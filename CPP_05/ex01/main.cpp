#include "Form.hpp"
#include <iostream>

int main(void)
{
    try
    {
        Form a("form1", 1, 1);
        Form c("form2", 2, 1);
        Bureaucrat b("Bureaucrat1", 1);

        std::cout << a << std::endl;
        std::cout << "***********************************" << std::endl;
        std::cout << c << std::endl;
        std::cout << "***********************************" << std::endl;
        b.decrement();
        b.signForm(a);
        c.beSigned(b);
        std::cout << a << std::endl;
        std::cout << "***********************************" << std::endl;
        std::cout << c << std::endl;
        std::cout << "***********************************" << std::endl;
        a.beSigned(b);
    }
    catch (std::exception &e)
    {
        std::cout <<  e.what() << std::endl;
    }
    return (0);
}
