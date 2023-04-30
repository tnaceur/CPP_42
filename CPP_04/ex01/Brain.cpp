#include "Brain.hpp"

Brain::Brain (void)
{
    std::cout << "\033[1;31mBrain Default Constructur called\033[0m" << std::endl;
}

Brain::Brain (const Brain& other)
{
    *this = other;
    std::cout << "\033[1;31mBrain Copy Constructur called\033[0m" << std::endl;
}

Brain	&Brain::operator=(const Brain& other)
{
    for (int i = 0; i < 100 ; i++)
        this->ideas[i] = other.ideas[i];
    return  *this;
}

Brain::~Brain(void)
{
    std::cout << "\033[1;31mBrain Destructur called\033[0m" << std::endl;
}
