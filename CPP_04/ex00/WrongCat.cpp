#include "WrongCat.hpp"

WrongCat::WrongCat ()
{
    type = "WrongCat";
    std::cout << "\033[1;31mWrongCat Default Constructur called\033[0m" << std::endl;
}

WrongCat::WrongCat (const WrongCat& other)
{
    *this = other;
    std::cout << "\033[1;31mWrongCat Copy Constructur called\033[0m" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat& other)
{
    this->type = other.type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "\033[1;31mWrongCat Destructur called\033[0m" << std::endl;
}

const std::string WrongCat::getType() const
{
    return type;
}

void    WrongCat::makeSound() const
{
    std::cout << "WrongCat make Sound\n";
}