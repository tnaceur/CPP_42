#include "easyfind.hpp"
#include <exception>
#include <forward_list>
#include <list>
#include <vector>
#include <set>
#include <deque>

int main()
{
    try
    {
        std::deque<int> container;
        container.push_back(8);
        container.push_back(2);
        container.push_back(2);
        container.push_back(7);
        easyfind(container, 17);
        for (std::deque<int>::iterator it = container.begin(); it != container.end(); it++)
            std::cout << *it << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}