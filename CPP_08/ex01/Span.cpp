#include "Span.hpp"
#include <algorithm>
#include <exception>
#include <iostream>
#include <iterator>
#include <new>
#include <vector>

Span::Span()
{
    size = 0;
}

Span::Span(unsigned int N)
{
    size = N;
}

Span::~Span()
{
}

Span::Span(const Span& cp)
{
    *this = cp;
}

Span& Span::operator=(const Span& cp)
{
    size = cp.size;
    list = cp.list;
    return *this;
}

int Span::longestSpan()
{
    if (list.size() <= 1)
        throw std::bad_exception();
    std::vector<int> sorted = list;
    std::sort(sorted.begin(), sorted.end());
    std::vector<int>::iterator first = sorted.begin();
    std::vector<int>::iterator last = sorted.end();
    return (*(--last) - *first);
}

int Span::shortestSpan()
{
    int minDistance = std::numeric_limits<int>::max();
    int size = list.size();

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            int distance = std::abs(list[i] - list[j]);
            minDistance = std::min(minDistance, distance);
        }
    }
    return minDistance;
}

void    Span::addNumber(int num)
{
    if (size <= list.size())
        throw std::bad_alloc();
    list.push_back(num);
}
