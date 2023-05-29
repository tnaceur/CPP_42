#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <sstream>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

void ToChar(std::string& str, int& x, int& y)
{
    for (int i = 0; str[i]; i++)
    {
        if (std::isdigit(str[i]))
            x = 1;
        if (std::isprint(str[i]) && !std::isdigit(str[i]))
            y = 1;
    }
    if (y && str.length() == 1)
        std::cout << "char: " << str << std::endl;
    else if (x && !y)
    {
        if (std::isprint(std::atoi(str.c_str())))
            std::cout << "char: " << static_cast<char>(std::atoi(str.c_str())) << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
}

void    ScalarConverter::convert(std::string& str)
{
    int x = 0 , y = 0;
    /* Char */
        ToChar(str, x, y);
    /* Int */
    if (x && y && str[0] != '+' && str[0] != '-')
        std::cout << "int: impossible" << std::endl;
    else
    {
        std::cout << "int: " << std::atoi(str.c_str()) << std::endl;
    }

}
