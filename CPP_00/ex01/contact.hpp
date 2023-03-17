#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class contact
{
    std::string f_name, l_name, nickname, phone, secret;
public:
    void setter(int n, std::string data)
    {
        if (n == 1)
            f_name = data;
        else if (n == 2)
            l_name = data;
        else if (n == 3)
            nickname = data;
        else if (n == 4)
            phone = data;
        else if (n == 5)
            secret = data;
    };
    std::string getter(int n)
    {
        if (n == 1)
            return (f_name);
        else if (n == 2)
            return (l_name);
        else if (n == 3)
            return (nickname);
        else if (n == 4)
            return (phone);
        else if (n == 5)
            return (secret);
        return NULL;
    };
};

#endif