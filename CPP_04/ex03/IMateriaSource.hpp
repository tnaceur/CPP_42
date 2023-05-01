#define IMATERTIASOURCE_HPP
#define IMATERTIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *inventory[4];
    public:
        MateriaSource(){
            for (int i = 0; i < 4; i++)
                this->inventory[i] = NULL;
        }
        MateriaSource(const MateriaSource &copy)
        {
            *this = copy;
        }
        MateriaSource &operator=(const MateriaSource &copy)
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
        ~MateriaSource(){
            for (int i = 0; i < 4; i++)
            {
                if (this->inventory[i] != NULL)
                    delete this->inventory[i];
            }
        }
        void learnMateria(AMateria* m)
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
        AMateria* createMateria(std::string const & type)
        {
            for (int i = 0; i < 4; i++)
            {
                if (this->inventory[i] != NULL && this->inventory[i]->getType() == type)
                    return (this->inventory[i]->clone());
            }
            return (NULL);
        }
};

#endif