#include "Cat.hpp"

Cat::Cat ()
{
    type = "Cat";
    std::cout << "\033[1;31mCat Default Constructur called\033[0m" << std::endl;
}

Cat::Cat (const Cat& other)
{
    *this = other;
    std::cout << "\033[1;31mCat Copy Constructur called\033[0m" << std::endl;
}

Cat	&Cat::operator=(const Cat& other)
{
    this->type = other.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "\033[1;31mCat Destructur called\033[0m" << std::endl;
}

const std::string Cat::getType() const
{
    return type;
}

void    Cat::makeSound() const
{
    std::cout << "Cat make Sound\n";
}