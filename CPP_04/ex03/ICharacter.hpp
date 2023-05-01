#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include "AMateria.hpp"


class Character : public ICharacter
{
private:
    std::string name;
    AMateria *inventory[4];
    AMateria *inventory1[4];
public:
    Character();
    Character(const Character &copy);
    Character &operator=(const Character &copy);
    Character(std::string name);
    ~Character();
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif