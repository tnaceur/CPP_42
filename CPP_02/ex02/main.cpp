#include "Fixed.hpp"

// void    print_(int fixed)
// {
//     int x;
//     std::string string;

//     for(int i = 0; i < 32; i++)
//     {
//         x = fixed & 1;
//         if (x)
//             string += "1";
//         else
//             string += "0";
//         fixed = fixed >> 1;
//     }
//     for (int i = 31; i >= 0 ; i--)
//     {
//         std::cout << string[i];
//         if (!(i % 8))
//             std::cout <<  " ";
//     }
//     std::cout << std::endl;
// }

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}