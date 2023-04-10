#include "Fixed.hpp"

/* Default constructor */

Fixed::Fixed()
{
    fix = 0;
    std::cout << "Default constructor" << std::endl;
}

/* Copy Assignment Operator */

Fixed &Fixed::operator=(const Fixed& a)
{
    this->fix = a.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const{
    return fix;
}

void Fixed::setRawBits(int const raw)
{
    fix = raw;
}

/* Copy Constructor */

Fixed::Fixed(const Fixed& a)
{
    std::cout << "Copy Constructor" << std::endl;
    *this = a;
}

/* Destructor */

Fixed::~Fixed() {
    std::cout << "Fixed Destructor" << std::endl;
}