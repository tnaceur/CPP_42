#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include "AMateria.hpp"

class ICharacter
{
public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

class character : public ICharacter
{
private:
    std::string name;
    AMateria *inventory[4];
public:
    character(){
        this->name = "default";
        for (int i = 0; i < 4; i++)
            this->inventory[i] = NULL;
    }
    character(const character &copy)
    {
        *this = copy;
    }
    character &operator=(const character &copy)
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
    character(std::string name)
    {
        this->name = name;
        for (int i = 0; i < 4; i++)
            this->inventory[i] = NULL;
    }
    ~character(){
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