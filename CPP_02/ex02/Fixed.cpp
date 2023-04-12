
#include "Fixed.hpp"

/* Default constructor */

Fixed::Fixed()
{
    fix = 0;
    //std::cout << "Default constructor called" << std::endl;
}

/* Parametrised Constructor */

Fixed::Fixed(int value)
{
    fix = value << frac;
}

Fixed::Fixed(float value)
{
    fix = roundf(value * (1 << frac));
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

bool Fixed::operator!=(const Fixed& b) const{
    return (this->getRawBits() != b.getRawBits());
}

bool Fixed::operator<(const Fixed& b) const{
    return (this->getRawBits() < b.getRawBits());
}

bool Fixed::operator>(const Fixed& b) const{
    return (this->getRawBits() > b.getRawBits());
}

bool Fixed::operator<=(const Fixed& b) const{
    return (this->getRawBits() <= b.getRawBits());
}

bool Fixed::operator>=(const Fixed& b) const{
    return (this->getRawBits() >= b.getRawBits());
}

bool Fixed::operator==(const Fixed& b) const{
    return (this->getRawBits() == b.getRawBits());
}

Fixed Fixed::operator*(const Fixed& b) const
{
    Fixed tmp;
    tmp.setRawBits(fix * b.getRawBits());
    tmp.setRawBits(tmp.toFloat());
    return tmp;
}

Fixed Fixed::operator+(const Fixed& b) const
{
    Fixed tmp;
    tmp.setRawBits(fix + b.getRawBits());
    return tmp;
}

Fixed Fixed::operator-(const Fixed& b) const
{
    Fixed tmp;
    tmp.setRawBits(fix - b.getRawBits());
    return tmp;
}

Fixed Fixed::operator/(const Fixed& b) const
{
    return Fixed((fix / b.getRawBits()));
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    ++fix;
    return tmp;
}

Fixed Fixed::operator++()
{
    fix++;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    --fix;
    return tmp;
}

Fixed Fixed::operator--()
{
    fix--;
    return *this;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
    if (a > b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
    if (a < b)
        return a;
    return b;
}

