
#include "Fixed.hpp"

/* Default constructor */

Fixed::Fixed()
{
    fix = 0;
    std::cout << "Default constructor called" << std::endl;
}

/* Parametrised Constructor */

Fixed::Fixed(int value)
{
    fix = value << frac;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float value)
{
    fix = roundf(value * (1 << frac));
    std::cout << "Float constructor called" << std::endl;
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
   *this = a;
}

/* Destructor */

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt () const
{
    return (fix >> frac);
}

float Fixed::toFloat () const
{
    return ((float)fix / (1 << frac));
}

/* Overload Operator */

std::ostream &operator<<(std::ostream &stream, const Fixed& a)
{
    stream << a.toFloat();
    return stream;
}
