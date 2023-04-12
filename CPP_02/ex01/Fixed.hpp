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
    Fixed(const int);
    Fixed(const float);
    ~Fixed();
    Fixed &operator=(const Fixed& a);
    Fixed(const Fixed& a);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt() const;
    float toFloat () const;
};

std::ostream &operator<<(std::ostream &stream, const Fixed& a);

#endif