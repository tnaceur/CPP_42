#include "Fixed.hpp"

const int Fixed::frac = 8;

void    print_(int fixed)
{
    int x;
    std::string string;

    for(int i = 0; i < 32; i++)
    {
        x = fixed & 1;
        if (x)
            string += "1";
        else
            string += "0";
        fixed = fixed >> 1;
    }
    for (int i = 31; i >= 0 ; i--)
    {
        std::cout << string[i];
        if (!(i % 8))
            std::cout <<  " ";
    }
    std::cout << std::endl;
}

int main( void )
{
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}
