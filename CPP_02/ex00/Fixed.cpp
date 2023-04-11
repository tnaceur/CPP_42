#include "Fixed.hpp"

/* Default constructor */

Fixed::Fixed()
{
    fix = 0;
    std::cout << "Default constructor called" << std::endl;
}

/* Copy Assignment Operator */

Fixed &Fixed::operator=(const Fixed& a)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fix = a.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return fix;
}

void Fixed::setRawBits(int const raw)
{
    fix = raw;
}

/* Copy Constructor */

Fixed::Fixed(const Fixed& a)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = a;
}

/* Destructor */

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}