#include "classes.hpp"
#include <iostream>

Base::~Base(){
}

class a{
public:
    virtual ~a();
};

class b : public a{

};

Base * generate(void)
{
    return new A();
}

void identify(Base* p)
{
    a *x = new b();
    a *ptr = dynamic_cast<b*>(x);
    if (ptr)
        std::cout << "here" << std::endl;
    else
        std::cout << "hello" << std::endl;

    if (dynamic_cast<A*>(p))
        std::cout << "The Classe is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "The Classe is B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "The Classe is C" << std::endl;
}

// void identify(Base& p)
// {
// }
