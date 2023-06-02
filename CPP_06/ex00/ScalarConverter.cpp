#include "ScalarConverter.hpp"
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <string>


ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}


bool canConvertToInt(const std::string& str)
{
    std::istringstream iss(str);
    int num;
    iss >> num;
    return !(iss.fail() || iss.bad()) && iss.eof();
}

bool canConvertToFloat(const std::string& str)
{
    std::istringstream iss(str);
    float num;
    iss >> num;
    return !(iss.fail() || iss.bad()) && iss.eof();
}

bool canConvertToDouble(const std::string& str)
{
    std::istringstream iss(str);
    double num;
    iss >> num;
    return !(iss.fail() || iss.bad()) && iss.eof();
}

void    defineNumber(std::string& str, int& x, int& y, int &point_num)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '.')
            point_num++;
        if (std::isdigit(str[i]))
            x = 1;
        if (std::isprint(str[i]) && !std::isdigit(str[i]))
            y = 1;
    }
}

/************************************* Char *********************************************/

void ToChar(std::string& str, int& x, int& y, int& point_num)
{
    if (y && str.length() == 1)
        std::cout << "char: " << str << std::endl;
    else if ((x && !y) || ((x && y
            && ((str[0] == '+' || str[0] == '-') || point_num)) && (str.find('+', 1) == std::string::npos && str.find('-', 1) == std::string::npos)))
    {
        if (std::isprint(std::atoi(str.c_str())))
            std::cout << "char: " << static_cast<char>(std::atoi(str.c_str())) << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
}

/************************************* Float *********************************************/

void    ToFloat(std::string& str, int& x, int& y)
{
    (void)x;
    if (y && str.length() == 1)
        std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
    else if (str == "nan" || str == "-inf" || str == "+inf")
    {
        std::cout << "float: " << str;
        if (str == "nan")
            std::cout << "f";
        std::cout<< std::endl;
    }
    else if (canConvertToFloat(str))
    {
        float n = static_cast<float>(std::atof(str.c_str()));
        int i_n = static_cast<int>(n);
        std::cout << "float: " << n;
        if (str.find(".") != std::string::npos && (n - i_n) != 0.0f)
            std::cout << "f";
        else
            std::cout << ".0f";
        std::cout << std::endl;
    }
    else
        std::cout << "float: impossible" << std::endl;
}

/************************************* Double *********************************************/

void    ToDouble(std::string &str, int &x, int &y)
{
    (void)x;
    if (y && str.length() == 1)
        std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
    else if (str == "nan" || str == "-inf" || str == "+inf")
        std::cout << "double: " << str << std::endl;
    else if (canConvertToDouble(str))
    {
        double n = static_cast<double>(std::atof(str.c_str()));
        int i_n = static_cast<int>(n);
        std::cout << "double: " << n;
        if (str.find(".") == std::string::npos || (n - i_n) == 0.0)
            std::cout << ".0";
        std::cout << std::endl;
    }
    else
        std::cout << "double: impossible" << std::endl;
}

void    ScalarConverter::convert(std::string& str)
{
    int x = 0 , y = 0, point_num = 0;

    defineNumber(str, x, y, point_num);

    if (point_num > 1)
        return (void)(std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl);
    
    if (str.find("f", str.length() - 1) != std::string::npos && point_num == 1)
        str.resize(str.size() - 1);

    /* Char */

        ToChar(str, x, y, point_num);

    /* Int */

        if (y && str.length() == 1)
            std::cout << "int : " << static_cast<int>(str[0]) << std::endl;
        else if ((canConvertToInt(str)) || (x && point_num))
            std::cout << "int: " << std::atoi(str.c_str()) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;

    /* Float */

        ToFloat(str, x, y);

    /* Double */

        ToDouble(str, x, y);
}
