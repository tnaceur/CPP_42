#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class contact
{
    std::string f_name, l_name, nickname, phone, secret;
public:
    void setter(int n, std::string data);
    std::string getter(int n);
};

#endif