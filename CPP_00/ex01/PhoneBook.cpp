#include "PhoneBook.hpp"

std::string    PhoneBook::c_get(int i, int j)
{
    return (list[i].getter(j));
}

void    PhoneBook::c_set(int i, int j, std::string data)
{
    return (list[i].setter(j, data));
}
