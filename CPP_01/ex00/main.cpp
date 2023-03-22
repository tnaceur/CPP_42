#include "Zombie.hpp"

int main()
{
    Zombie *zombie;

    randomChump("hello world");
    zombie = newZombie("taha");
    delete zombie;
}
