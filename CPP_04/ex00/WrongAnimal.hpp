#ifndef WRONGWrong_HPP
#define WRONGWrong_HPP

#include <iostream>

class	WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal ();
        WrongAnimal (const WrongAnimal&);
        WrongAnimal &operator=(const WrongAnimal&);
        ~WrongAnimal ();
        const std::string getType() const;
        void makeSound() const;
};

#endif