#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Hit_point(10) ,Energy_point(10), Attack_damage(0), Name("No_Name") {
    std::cout << "\033[1;31mClapTrap Default Constructur called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const std::string& n)
    : Hit_point(10) ,Energy_point(10), Attack_damage(0) , Name(n)
{
    std::cout << "\033[1;34mClapTrap Parametrized Constructur called\033[0m" << std::endl;
}

ClapTrap&  ClapTrap::operator=(const ClapTrap& other) {
    Name = other.Name;
    Hit_point = other.Hit_point;
    Energy_point = other.Energy_point;
    Attack_damage = other.Attack_damage;
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "\033[1;34mClapTrap Copy Constructor called\033[0m" << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap() {
    std::cout << "\033[1;34mClapTrap Destructor called\033[0m" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (!Hit_point)
        return (void)(std::cout << Name << " Is Dead\n");
    if (!Energy_point)
        return (void)(std::cout << "No point\n");
    else
        std::cout << "ClapTrap " << Name << " attacks " <<  target << ", causing " << Attack_damage << " points of damage!" << std::endl;
    Energy_point--;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (Hit_point <= amount)
        return (void)(std::cout << "ClapTrap " << Name << " is dead.\n");
    std::cout << "ClapTrap " << Name << " take " << amount <<  " of damage!" << std::endl;
    Hit_point -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (!Hit_point)
        return (void)(std::cout << Name << " Is Dead\n");
    if (!Energy_point)
        return (void)(std::cout << "No point\n");
    std::cout << "ClapTrap " << Name << " take " << amount <<  " of heal!" << std::endl;
    Hit_point += amount;
    Energy_point--;
}
