#include "PmergeMe.hpp"
#include <algorithm>
#include <iterator>
#include <ostream>
#include <utility>
#include <sstream>
#include <vector>

#define WRONG_ARG "Error: Wrong number of arguments"
#define NEGATIVE_NUM "Error: Negative Number."
#define INVALID_INPUT "Invalid input."


void    int_convert(std::string s, int& num)
{
    std::istringstream iss(s);
    iss >> num;
    if (!iss.eof() || iss.fail() || iss.bad())
        throw INVALID_INPUT;
}


void print(std::vector<std::pair<int , int> >& pairs)
{
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        std::cout << it->first << " ";
        std::cout << it->second << " ";
        // else if (!skip_last)
        //     std::cout << it->second << " ";
        // else
        // {
        //     std::cout << "Additional: " << it->second << std::endl;
        //     // it->second = -1;
        // }
    }
}

int main(int ac, char **av)
{
    try
    {
        if (ac == 1)
            throw WRONG_ARG;
        std::vector<int> smallest, largest;
        std::vector<std::pair<int, int> > pairs;
        for (int i = 1; i < ac; ++i)
        {
            int num;
            int_convert(av[i], num);
            if (num < 0)
                throw NEGATIVE_NUM;
            smallest.push_back(num);
        }

        for (std::vector<int>::iterator it = smallest.begin(); it != smallest.end(); it++)
        {
            pairs.push_back(std::make_pair(*it, *(it + 1)));
            if (it + 1 != smallest.end())
                it++;
        }
        if ((ac - 1) % 2 != 0)
            (pairs.end() - 1)->second = -1;
        print(pairs);
        std::cout << std::endl;
        for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        {
            if (it->first > it->second)
                std::swap(it->second, it->first);
        }
        smallest.clear();
        for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        {
            if (it->first != -1)
                smallest.push_back(it->first);
            largest.push_back(it->second);
        }
        std::cout << "Small = ";
        for (std::vector<int>::iterator it = smallest.begin(); it != smallest.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        std::cout << "Large = ";
        for (std::vector<int>::iterator it = largest.begin(); it != largest.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        for (std::vector<int>::iterator it = smallest.begin(); it != smallest.end(); ++it)
            largest.insert(std::lower_bound(largest.begin(), largest.end(), *it), *it);
        std::cout << "Large = ";
        for (std::vector<int>::iterator it = largest.begin(); it != largest.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
    }
    return 0;
}
