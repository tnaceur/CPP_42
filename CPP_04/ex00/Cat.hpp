#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal
{
    public:
        Cat ();
        ~Cat ();
        Cat (const Cat&);
        Cat &operator=(const Cat&);
        const std::string getType() const;
        void makeSound() const;
};

#endif