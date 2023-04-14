#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap1("taha");
    ClapTrap clap2 = clap1;
    clap2.attack("Bob");
    clap2.takeDamage(5);
    clap2.beRepaired(3);
    clap2 = clap1;
    return (0);
}
