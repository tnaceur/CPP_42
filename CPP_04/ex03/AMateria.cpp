#include "AMateria.hpp"

AMateria::AMateria()
{
    this->type = "default";
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* Default " << target.getName() << " *" << std::endl;
}

/* ******************************** Ice Class ******************************** */

Ice::Ice()
{
    this->type = "ice";
}

Ice::~Ice()
{
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

/* ******************************** Cure Class ******************************** */

Cure::Cure()
{
    this->type = "cure";
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}