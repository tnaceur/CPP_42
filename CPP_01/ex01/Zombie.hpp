#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
    std::string name;
public:
    void    announce(void);
    void    set_name(std::string);
    // Zombie(std::string);
    ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif