#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {
    std::string name;
    Weapon&     weapon;
public:
    void    attack();
    HumanA(std::string s, Weapon& w);
    ~HumanA();
};

#endif
