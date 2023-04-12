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
    Fixed(const Fixed& a);
    ~Fixed();
    static const Fixed& max(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& min(Fixed& a, Fixed& b);
    Fixed &operator=(const Fixed& a);
    bool operator<=(const Fixed& b) const;
    bool operator>=(const Fixed& b) const;
    bool operator<(const Fixed& b) const;
    bool operator>(const Fixed& b) const;
    bool operator==(const Fixed& b) const;
    bool operator!=(const Fixed& b) const;
    Fixed operator*(const Fixed& b) const;
    Fixed operator+(const Fixed& b) const;
    Fixed operator-(const Fixed& b) const;
    Fixed operator/(const Fixed& b) const;
    Fixed operator++(int);
    Fixed operator++();
    Fixed operator--(int);
    Fixed operator--();
    void setRawBits(int const raw);
    int getRawBits(void) const;
    int toInt() const;
    float toFloat () const;
};

std::ostream &operator<<(std::ostream &stream, const Fixed& a);

#endif