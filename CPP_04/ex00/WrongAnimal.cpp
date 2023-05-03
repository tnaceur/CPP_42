#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal (void)
{
    type = "";
    std::cout << "\033[1;31mWrongAnimal Default Constructur called\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal (const WrongAnimal& other)
{
    *this = other;
    std::cout << "\033[1;31mWrongAnimal Copy Constructur called\033[0m" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& other)
{
    this->type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "\033[1;31mWrongAnimal Destructur called\033[0m" << std::endl;
}

const std::string WrongAnimal::getType() const
{
    return type;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal make Sound\n";
}
