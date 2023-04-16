#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
    public:
        ScavTrap (const std::string&);
        ScavTrap ();
        ~ScavTrap ();
        ScavTrap (const ScavTrap&);
        ScavTrap &operator=(const ScavTrap&);

        void    guardGate();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        void print_() const;
        std::string getName() const;
        unsigned int getHit() const;
        unsigned int getEnergy() const;
        unsigned int getAttack() const;
};

#endif
