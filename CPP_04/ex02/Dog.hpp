#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
    Brain* brain;
    public:
        Dog ();
        ~Dog ();
        Dog (const Dog&);
        Dog &operator=(const Dog&);
        const std::string getType() const;
        void    makeSound() const;
};

#endif