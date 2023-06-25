#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <deque>
#include <iostream>
#include <iterator>
#include <ostream>
#include <utility>
#include <sstream>
#include <sys/time.h>
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

void print(std::vector<int> &smallest)
{
    for (size_t i = 0; i < smallest.size(); i++)
    {
        std::cout << smallest[i] << " ";
    }
    std::cout << std::endl;
}

void print(std::deque<int> &smallest)
{
    for (size_t i = 0; i < smallest.size(); i++)
    {
        std::cout << smallest[i] << " ";
    }
    std::cout << std::endl;
}

void vector_sort(int ac, char **av, std::vector<int>& before, double& time)
{
    std::vector<int> smallest, largest;
    std::vector<std::pair<int, int> > pairs;
    timeval start, end;
    for (int i = 1; i < ac; ++i)
    {
        int num;
        int_convert(av[i], num);
        if (num < 0)
            throw NEGATIVE_NUM;
        before.push_back(num);
    }
    gettimeofday(&start, NULL);
    for (std::vector<int>::iterator it = before.begin(); it != before.end(); it++)
    {
        // std::cout << *it << " ";
        pairs.push_back(std::make_pair(*it, *(it + 1)));
        if (it + 1 != before.end())
        {
            it++;
            // std::cout << *it << " ";
        }
    }
    // std::cout << std::endl;
    if ((ac - 1) % 2 != 0)
        (pairs.end() - 1)->second = -1;
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        if (it->first > it->second)
            std::swap(it->second, it->first);
    }
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        if (it->first != -1)
            smallest.push_back(it->first);
        largest.push_back(it->second);
    }
    std::sort(largest.begin(), largest.end());
    for (std::vector<int>::iterator it = smallest.begin(); it != smallest.end(); ++it)
        largest.insert(std::lower_bound(largest.begin(), largest.end(), *it), *it);
    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    time = seconds * 1000.0 + microseconds / 1000.0;
    // std::cout << "after = ";
    // for (std::vector<int>::iterator it = largest.begin(); it != largest.end(); ++it)
    // {
    //     std::cout << *it << std::endl;
    // }
    // std::cout << std::endl;
}

void deque_sort(int ac, char **av, std::deque<int>& after, double& time)
{
    std::deque<int> smallest;
    std::deque<std::pair<int, int> > pairs;
    timeval start, end;
    for (int i = 1; i < ac; ++i)
    {
        int num;
        int_convert(av[i], num);
        if (num < 0)
            throw NEGATIVE_NUM;
        smallest.push_back(num);
    }
    gettimeofday(&start, NULL);
    for (std::deque<int>::iterator it = smallest.begin(); it != smallest.end(); it++)
    {
        pairs.push_back(std::make_pair(*it, *(it + 1)));
        if (it + 1 != smallest.end())
            it++;
    }
    if ((ac - 1) % 2 != 0)
        (pairs.end() - 1)->second = -1;
    for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        if (it->first > it->second)
            std::swap(it->second, it->first);
    }
    smallest.clear();
    for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        if (it->first != -1)
            smallest.push_back(it->first);
        after.push_back(it->second);
    }
    std::sort(after.begin(), after.end());
    for (std::deque<int>::iterator it = smallest.begin(); it != smallest.end(); ++it)
        after.insert(std::lower_bound(after.begin(), after.end(), *it), *it);
    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    time = seconds * 1000.0 + microseconds / 1000.0;
}

int main(int ac, char **av)
{
    try
    {
        if (ac == 1)
            throw WRONG_ARG;
        std::vector<int> before;
        double v_time, d_time;
        vector_sort(ac, av, before, v_time);
        std::cout << "Before: ";
        print(before);
        std::deque<int> after;
        deque_sort(ac, av, after, d_time);
        std::cout << "After:  ";
        print(after);
        std::cout << "Time to process a range of " << before.size() <<  "elements with std::vector is : "
            << v_time << " us" << std::endl;
        std::cout << "Time to process a range of " << before.size() <<  "elements with std::deque is : "
            << d_time << " us" << std::endl;
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
    }
    return 0;
}
