#include "Form.hpp"
#include <iostream>

int main(void)
{
    try
    {
        Form a("form", 1, 1);
        Bureaucrat b("Taha", 1);

        a.beSigned(b);
        b.decrement();
        b.signForm(a);

        std::cout << b << std::endl;
        // a.increment();
        // std::cout << a << std::endl;
        // a.decrement();
        // std::cout << a << std::endl;
        // a.decrement();
    }
    catch (std::exception &e)
    {
        std::cout <<  e.what() << std::endl;
    }
    return (0);
}
