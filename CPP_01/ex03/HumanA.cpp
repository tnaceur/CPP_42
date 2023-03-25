#include "HumanA.hpp"

void    HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string s, Weapon& w) : name(s), weapon(w)
{
    std::cout << "\"HumanA Constructure Called\"" << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "\"HumanA Destructor is called\"" << std::endl;
}
