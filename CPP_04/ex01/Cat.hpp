#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
    Brain* brain;
    public:
        Cat ();
        ~Cat ();
        Cat (const Cat&);
        Cat &operator=(const Cat&);
        const std::string getType() const;
        void makeSound() const;
};

#endif