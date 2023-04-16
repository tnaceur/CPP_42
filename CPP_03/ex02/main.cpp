#include "FragTrap.hpp"

int main()
{
    FragTrap p1("taha");
    FragTrap p2("bot");
    p1.print_();
    std::cout << "--------------------------" << std::endl;
    p2.print_();
    std::cout << "--------------------------" << std::endl;
    p1.print_();
    std::cout << "--------------------------" << std::endl;
    p1.attack(p2.getName());
    p2.takeDamage(p1.getAttack());
    std::cout << "--------------------------" << std::endl;
    p2.print_();
    std::cout << "--------------------------" << std::endl;
    p2.beRepaired(10);
    // std::cout << "--------------------------" << std::endl;
    std::cout << "--------------------------" << std::endl;
    p2.print_();
    std::cout << "--------------------------" << std::endl;
    p1.highFivesGuys();
}
