#include "ScalarConverter.hpp"
#include <string>

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "Wrong Arguments" << std::endl, 1);
    std::string str = av[1];
    ScalarConverter::convert(str);
}