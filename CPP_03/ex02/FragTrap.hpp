#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class	FragTrap : public ClapTrap
{
    public:
        FragTrap (const std::string&);
        FragTrap ();
        ~FragTrap ();
        FragTrap (const FragTrap&);
        FragTrap &operator=(const FragTrap&);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void highFivesGuys(void);

        void print_() const;
        std::string getName() const;
        unsigned int getHit() const;
        unsigned int getEnergy() const;
        unsigned int getAttack() const;
};

#endif