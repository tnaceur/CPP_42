#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::set_name(std::string a)
{
    name = a;
}

Zombie::Zombie(std::string n)
{
    name = n;
}

Zombie::~Zombie()
{
    std::cout << name << " : the destructure is called" << std::endl;
}