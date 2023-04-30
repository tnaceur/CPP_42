#include "Cat.hpp"

Cat::Cat ()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "\033[1;31mCat Default Constructur called\033[0m" << std::endl;
}

Cat::Cat (const Cat& other)
{
    brain = new Brain();
    *this = other;
    std::cout << "\033[1;31mCat Copy Constructur called\033[0m" << std::endl;
}

Cat	&Cat::operator=(const Cat& other)
{
    this->type = other.type;
    *(this->brain) = *(other.brain);
    return *this;
}


const std::string Cat::getType() const
{
    return type;
}

void    Cat::makeSound() const
{
    std::cout << "Cat make Sound\n";
}

Cat::~Cat()
{
    delete brain;
    std::cout << "\033[1;31mCat Destructur called\033[0m" << std::endl;
}