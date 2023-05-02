#include "ICharacter.hpp"

ICharacter::~ICharacter()
{
}

/* ********************** Character Class ***************************** */

Character::Character()
{
    this->name = "default";
    for (int i = 0; i < 4; i++)
    {
        this->inventory1[i] = NULL;
        this->inventory[i] = NULL;
    }
}

Character::Character(const Character &copy)
{
    *this = copy;
}

Character &Character::operator=(const Character &copy)
{
    this->name = copy.name;
    for (int i = 0; i < 4; i++)
    {
        if (copy.inventory[i] != NULL)
            this->inventory[i] = copy.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
        this->inventory1[i] = NULL;
    }
    return (*this);
}

Character::Character(std::string name)
{
    this->name = name;
    for (int i = 0; i < 4; i++)
    {
        this->inventory1[i] = NULL;
        this->inventory[i] = NULL;
    }
}

Character::~Character(){
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] != NULL)
            delete this->inventory[i];
        if (this->inventory1[i] != NULL)
            delete this->inventory1[i];
    }
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory1[i] != NULL)
        {
            delete this->inventory1[i];
            this->inventory1[i] = NULL;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == NULL)
        {
            this->inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory1[i] == NULL && this->inventory[idx] != NULL)
        {
            this->inventory1[i] = this->inventory[idx];
            break ;
        }
    }
    this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
        return ;
    if (this->inventory[idx] != NULL)
        this->inventory[idx]->use(target);
}
