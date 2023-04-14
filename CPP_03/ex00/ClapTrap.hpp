#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    unsigned int Hit_point;
    unsigned int Energy_point;
    unsigned int Attack_damage;
    std::string Name;
public:
    ClapTrap();
    ~ClapTrap();

    ClapTrap(std::string Name);
    ClapTrap(const ClapTrap&);
    ClapTrap &operator=(const ClapTrap&);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
