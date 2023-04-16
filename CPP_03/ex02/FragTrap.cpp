#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& value) : ClapTrap(value)
{
    Hit_point = 100;
    Energy_point = 100;
    Attack_damage = 30;
    std::cout << "\033[1;31mFragTrap Parametrised Constructur called\033[0m" << std::endl;
}

FragTrap::FragTrap (void)
{
    std::cout << "\033[1;31mFragTrap Default Constructur called\033[0m" << std::endl;
}

FragTrap::FragTrap (const FragTrap& other)
{
    std::cout << "\033[1;31mFragTrap Copy Constructur called\033[0m" << std::endl;
    *this = other;
}

FragTrap	&FragTrap::operator=(const FragTrap& other)
{
    this->Name = other.Name;
    this->Hit_point = other.Hit_point;
    this->Energy_point = other.Energy_point;
    this->Attack_damage = other.Attack_damage;
    return *this;
}

FragTrap::~FragTrap(void)
{
    std::cout << "\033[1;31mFragTrap Destructur called\033[0m" << std::endl;
}

void    FragTrap::print_() const{
    std::cout << "Name : "  << Name << std::endl;
    std::cout << "Hit_point : "  << Hit_point << std::endl;
    std::cout << "Energy_point : "  << Energy_point << std::endl;
    std::cout << "Attack_damage : "  << Attack_damage << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (!Hit_point) 
        return (void)(std::cout << Name << " Is Dead\n");
    if (!Energy_point)
        return (void)(std::cout << "No point\n");
    else
        std::cout << "FragTrap " << Name << " attacks " <<  target << ", causing " << Attack_damage << " points of damage!" << std::endl;
    Energy_point--;
}

void    FragTrap::takeDamage(unsigned int amount)
{
    if (Hit_point <= amount)
        return (void)(std::cout << "ClapTrap " << Name << " is dead.\n");
    std::cout << "FragTrap " << Name << " take " << amount <<  " of damage!" << std::endl;
    Hit_point -= amount;
}

void    FragTrap::beRepaired(unsigned int amount)
{
    if (!Hit_point)
        return (void)(std::cout << Name << " is dead\n");
    if (!Energy_point)
        return (void)(std::cout << "No point\n");
    std::cout << "FragTrap " << Name << " take " << amount <<  " of heal!" << std::endl;
    Hit_point += amount;
    Energy_point--;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << " High : 🖐 !" << std::endl;
}

std::string FragTrap::getName() const{
    return Name;
}

unsigned int FragTrap::getHit() const{
    return Hit_point;
}

unsigned int FragTrap::getEnergy() const{
    return Energy_point;
}

unsigned int FragTrap::getAttack() const{
    return Attack_damage;
}
