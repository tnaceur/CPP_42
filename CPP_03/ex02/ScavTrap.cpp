#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    Hit_point = 100;
    Energy_point = 50;
    Attack_damage = 20;
    std::cout << "\033[1;31mScavTrap Parametrised Constructur called\033[0m" << std::endl;
}

ScavTrap::ScavTrap (void)
{
    Hit_point = 100;
    Energy_point = 50;
    Attack_damage = 20;
    Name = "No_name";
    std::cout << "\033[1;31mScavTrap Default Constructur called\033[0m" << std::endl;
}

ScavTrap::ScavTrap (const ScavTrap& other)
{
    std::cout << "\033[1;31mScavTrap Copy Constructur called\033[0m" << std::endl;
    *this = other;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "\033[1;31mScavTrap Destructur called\033[0m" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap& other)
{
    this->Name = other.Name;
    this->Hit_point = other.Hit_point;
    this->Attack_damage = other.Attack_damage;
    this->Energy_point = other.Energy_point;
    return *this;
}

void    ScavTrap::print_() const{
    std::cout << "Name : "  << Name << std::endl;
    std::cout << "Hit_point : "  << Hit_point << std::endl;
    std::cout << "Energy_point : "  << Energy_point << std::endl;
    std::cout << "Attack_damage : "  << Attack_damage << std::endl;
}


void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << Name << " in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (!Hit_point) 
        return (void)(std::cout << Name << " Is Dead\n");
    if (!Energy_point)
        return (void)(std::cout << "No point\n");
    else
        std::cout << "ScavTrap " << Name << " attacks " <<  target << ", causing " << Attack_damage << " points of damage!" << std::endl;
    Energy_point--;
}

void    ScavTrap::takeDamage(unsigned int amount)
{
    if (Hit_point <= amount)
        return (void)(std::cout << "ClapTrap " << Name << " is dead.\n");
    std::cout << "ScavTrap " << Name << " take " << amount <<  " of damage!" << std::endl;
    Hit_point -= amount;
}

void    ScavTrap::beRepaired(unsigned int amount)
{
    if (!Hit_point)
        return (void)(std::cout << Name << " is dead\n");
    if (!Energy_point)
        return (void)(std::cout << "No point\n");
    std::cout << "ScavTrap " << Name << " take " << amount <<  " of heal!" << std::endl;
    Hit_point += amount;
    Energy_point--;
}

std::string ScavTrap::getName() const{
    return Name;
}

unsigned int ScavTrap::getHit() const{
    return Hit_point;
}

unsigned int ScavTrap::getEnergy() const{
    return Energy_point;
}

unsigned int ScavTrap::getAttack() const{
    return Attack_damage;
}
