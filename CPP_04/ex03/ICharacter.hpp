#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include "AMateria.hpp"


class Character : public ICharacter
{
private:
    std::string name;
    AMateria *inventory[4];
public:
    Character(){
        this->name = "default";
        for (int i = 0; i < 4; i++)
            this->inventory[i] = NULL;
    }
    Character(const Character &copy)
    {
        *this = copy;
    }
    Character &operator=(const Character &copy)
    {
        this->name = copy.name;
        for (int i = 0; i < 4; i++)
        {
            if (copy.inventory[i] != NULL)
                this->inventory[i] = copy.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
        return (*this);
    }
    Character(std::string name)
    {
        this->name = name;
        for (int i = 0; i < 4; i++)
            this->inventory[i] = NULL;
    }
    ~Character(){
        for (int i = 0; i < 4; i++)
        {
            if (this->inventory[i] != NULL)
                delete this->inventory[i];
        }
    }
    std::string const & getName() const
    {
        return (this->name);
    }
    void equip(AMateria* m)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->inventory[i] == NULL)
            {
                this->inventory[i] = m;
                break;
            }
        }
    }
    void unequip(int idx)
    {
        if (idx < 0 || idx > 3)
            return ;
        this->inventory[idx] = NULL;
    }
    void use(int idx, ICharacter& target)
    {
        if (idx < 0 || idx > 3)
            return ;
        if (this->inventory[idx] != NULL)
            this->inventory[idx]->use(target);
    }
};

#endif