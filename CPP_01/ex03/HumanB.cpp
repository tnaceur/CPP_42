#include "HumanB.hpp"

void    HumanB::attack()
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

HumanB::HumanB(std::string s)
{
    std::cout << "\"HumanB Constructure Called\"" << std::endl;
    name = s;
    weapon = NULL;
}

void    HumanB::setWeapon(Weapon &a)
{
    weapon = &a;
}

HumanB::~HumanB()
{
    std::cout << "\"HumanB Destructure Called\"" << std::endl;
}
