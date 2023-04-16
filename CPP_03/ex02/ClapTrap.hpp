#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
protected:
    unsigned int Hit_point;
    unsigned int Energy_point;
    unsigned int Attack_damage;
    std::string Name;
public:

    ClapTrap(const std::string&);
    ClapTrap(const ClapTrap&);
    ClapTrap();
    ~ClapTrap();
    ClapTrap &operator=(const ClapTrap&);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
