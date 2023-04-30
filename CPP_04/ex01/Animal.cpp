#include "Animal.hpp"

Animal::Animal (void)
{
    type = "";
    std::cout << "\033[1;31mAnimal Default Constructur called\033[0m" << std::endl;
}

Animal::Animal (const Animal& other)
{
    *this = other;
    std::cout << "\033[1;31mAnimal Copy Constructur called\033[0m" << std::endl;
}

Animal	&Animal::operator=(const Animal& other)
{
    this->type = other.type;
    return *this;
}

Animal::~Animal(void)
{
    std::cout << "\033[1;31mAnimal Destructur called\033[0m" << std::endl;
}

const std::string Animal::getType() const
{
    return type;
}

void    Animal::makeSound() const
{
    std::cout << "Animal make Sound\n";
}
