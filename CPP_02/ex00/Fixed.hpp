#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed{
    int fix;
    static const int frac;
public:
    Fixed();
    ~Fixed();
    Fixed &operator=(const Fixed& a);
    Fixed(const Fixed& a);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif