#ifndef IMATERTIASOURCE_HPP
#define IMATERTIASOURCE_HPP

#include <iostream>
#include "ICharacter.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *inventory[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &copy);
        MateriaSource &operator=(const MateriaSource &copy);
        ~MateriaSource();
        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);
};

#endif