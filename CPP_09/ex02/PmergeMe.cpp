#include "PmergeMe.hpp"

void    int_convert(std::string s, int& num)
{
    std::istringstream iss(s);
    iss >> num;
    if (!iss.eof() || iss.fail() || iss.bad())
        throw INVALID_INPUT;
}

void print(std::list<int> &smallest)
{
    for (std::list<int>::iterator it = smallest.begin(); it != smallest.end(); it++)
    {
        std::cout << *it << " ";
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

void list_sort(int ac, char **av, std::list<int>& before, double& time)
{
    std::list<int> smallest, largest;
    std::list<std::pair<int, int> > pairs;
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
    for (std::list<int>::iterator it = before.begin(); it != before.end(); it++)
    {
        std::list<int>::iterator it2 = it;
        it2++;
        pairs.push_back(std::make_pair(*it, *(it2)));
        if (it2 != before.end())
            it++;
    }
    if ((ac - 1) % 2 != 0)
        (--pairs.end())->second = -1;
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        if (it->first > it->second)
            std::swap(it->second, it->first);
    }
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        if (it->first != -1)
            smallest.push_back(it->first);
        largest.push_back(it->second);
    }
    largest.sort();
    for (std::list<int>::iterator it = smallest.begin(); it != smallest.end(); ++it)
        largest.insert(std::lower_bound(largest.begin(), largest.end(), *it), *it);
    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    time = seconds * 1000.0 + microseconds / 1000.0;
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
