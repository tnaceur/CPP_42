#include "ClapTrap.hpp"

int main()
{
    ClapTrap p1("taha");
    ClapTrap p2("bot");
    p1.print_();
    std::cout << "--------------------------" << std::endl;
    p2.print_();
    std::cout << "--------------------------" << std::endl;
    p1.beRepaired(10);
    std::cout << "--------------------------" << std::endl;
    p1.print_();
    std::cout << "--------------------------" << std::endl;
    p1.attack(p2.getName());
    p2.takeDamage(p1.getAttack());
    std::cout << "--------------------------" << std::endl;
    p2.print_();
    std::cout << "--------------------------" << std::endl;
    p1.print_();
}
