#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>

template <typename T>
int easyfind(T& container, int i)
{
    typename T::iterator result = std::find(container.begin(), container.end(), i);
    if (result != container.end())
    {
        std::cout << i << " Found at index: " << std::distance(container.begin(), result) << std::endl;
        return std::distance(container.begin(), result);
    }
    throw std::out_of_range("Element not found!");
}

#endif