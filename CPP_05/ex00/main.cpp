#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat a("Taha", 150);
        std::cout << a << std::endl;
        a.increment();
        std::cout << a << std::endl;
        a.decrement();
        std::cout << a << std::endl;
        a.decrement();
    }
    catch (std::exception &e)
    {
        std::cout <<  e.what() << std::endl;
    }
    return (0);
}
