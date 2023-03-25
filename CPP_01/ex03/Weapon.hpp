#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
    std::string type;
public:
    const std::string& getType(void);
    void setType(std::string);
    Weapon();
    Weapon(const std::string);
    ~Weapon();
};

#endif
