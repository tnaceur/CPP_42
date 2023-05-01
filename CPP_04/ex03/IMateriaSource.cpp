#include "IMateriaSource.hpp"

IMateriaSource::~IMateriaSource()
{
}

/* ************************************* MateriaSource Class ***************************** */

MateriaSource::MateriaSource(){
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    *this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
    for (int i = 0; i < 4; i++)
    {
        if (copy.inventory[i] != NULL)
            this->inventory[i] = copy.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
    return (*this);
}

MateriaSource::~MateriaSource(){
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] != NULL)
            delete this->inventory[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
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

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] != NULL && this->inventory[i]->getType() == type)
            return (this->inventory[i]->clone());
    }
    return (NULL);
}