#ifndef PHONBOOK_HPP
#define PHONBOOK_HPP

#include <iostream>
#include "contact.hpp"

class phonebook {
    contact list[8];
    public:
        std::string    c_get(int i, int j);
        void    c_set(int i, int j, std::string data);
};

#endif