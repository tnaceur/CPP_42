#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal
{
    protected:
        std::string type;
    public:
        Animal ();
        Animal (const Animal&);
        Animal &operator=(const Animal&);
        virtual ~Animal ();
        virtual const std::string getType() const = 0;
        virtual void makeSound() const = 0;
};

#endif