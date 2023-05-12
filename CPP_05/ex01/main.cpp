#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    try
    {
        Form a("taha", 1, 1);
        std::cout << a << std::endl;
        // Bureaucrat a("Taha", 150);
        // std::cout << a << std::endl;
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
