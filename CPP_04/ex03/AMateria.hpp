#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "Interfaces.hpp"

class	Ice : public AMateria
{
    public:
        Ice ();
        AMateria* clone() const;
        void use(ICharacter& target);
        ~Ice ();
};

class	Cure : public AMateria
{
    public:
        Cure ();
        AMateria* clone() const;
        void use(ICharacter& target);
        ~Cure ();
};

#endif