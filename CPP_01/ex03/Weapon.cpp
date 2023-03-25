#include "Weapon.hpp"

const std::string& Weapon::getType(void)
{
    return (type);
}

void Weapon::setType(std::string t)
{
    type = t;
}

Weapon::Weapon()
{
    std::cout << "\"Weapon Constructor Called\"" << std::endl;
}

Weapon::~Weapon()
{
    std::cout << "\"Weapon Destructure Called\"" << std::endl;
}

Weapon::Weapon(std::string s)
{
    std::cout << "\"Weapon Constructor Called to set type\"" << std::endl;
    type = s;
}
