#include "Zombie.hpp"

int main(void)
{
    int N = 10;
    Zombie *z = zombieHorde(N, "Hello world");
    for (int i = 0; i < N; i++)
        z[i].announce();
    delete[] z;
}
