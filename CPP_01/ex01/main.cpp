#include "Zombie.hpp"

int main()
{
    Zombie *z = zombieHorde(10, "taha");
    for (int i = 0; i < 10; i++)
        z[i].announce();
}
