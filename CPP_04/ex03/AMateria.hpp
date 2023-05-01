#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria()
        {
            this->type = "default";
        }
        virtual ~AMateria() {}
        AMateria(std::string const & type);
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target)
        {
            (void)target;
        }
};

class ICharacter
{
public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
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