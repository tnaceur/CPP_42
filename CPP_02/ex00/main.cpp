#include "Fixed.hpp"

const int Fixed::frac = 8;

int main(void)
{
    Fixed a;
    Fixed b( a );
    Fixed c;
    c = b;
    (a = b) = c;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}
