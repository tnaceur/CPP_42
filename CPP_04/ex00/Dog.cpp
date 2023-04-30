#include "Dog.hpp"

Dog::Dog ()
{
    type = "Dog";
    std::cout << "\033[1;31mDog Default Constructur called\033[0m" << std::endl;
}

Dog::Dog (const Dog& other)
{
    *this = other;
    std::cout << "\033[1;31mDog Copy Constructur called\033[0m" << std::endl;
}

Dog	&Dog::operator=(const Dog& other)
{
    this->type = other.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "\033[1;31mDog Destructur called\033[0m" << std::endl;
}

const std::string Dog::getType() const
{
    return type;
}

void    Dog::makeSound() const
{
    std::cout << "Dog make Sound\n";
}
