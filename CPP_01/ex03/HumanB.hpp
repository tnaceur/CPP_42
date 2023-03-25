#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
    std::string name;
    Weapon      *weapon;
public:
    void    attack();
    HumanB(std::string);
    ~HumanB();
    void    setWeapon(Weapon &a);
};

#endif
