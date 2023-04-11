#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed{
    int fix;
    static const int frac = 8;
public:
    Fixed();
    Fixed(int);
    Fixed(float);
    ~Fixed();
    Fixed &operator=(const Fixed& a);
    static Fixed& max(Fixed& a, Fixed& b);
    Fixed(const Fixed& a);
    bool operator<=(const Fixed& b) const;
    bool operator>=(const Fixed& b) const;
    bool operator<(const Fixed& b) const;
    bool operator>(const Fixed& b) const;
    bool operator==(const Fixed& b) const;
    bool operator!=(const Fixed& b) const;
    Fixed& operator*(const Fixed& b) const;
    Fixed& operator++(int);
    Fixed& operator++();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt() const;
    float toFloat () const;
};

std::ostream &operator<<(std::ostream &stream, const Fixed& a);

#endif