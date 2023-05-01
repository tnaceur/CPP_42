#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria(std::string const & type);
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

class	Ice : public AMateria
{
    public:
        Ice ()
        {
            this->type = "ice";
        }
        AMateria* clone() const
        {
            return (new Ice(*this));
        }
        void use(ICharacter& target)
        {
            std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
        }
        ~Ice ()
        {
        }
};

class	Cure : public AMateria
{
    public:
        Cure ()
        {
            this->type = "cure";
        }
        AMateria* clone() const
        {
            return (new Cure(*this));
        }
        void use(ICharacter& target)
        {
            std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
        }
        ~Cure ()
        {
        }
};

#endif