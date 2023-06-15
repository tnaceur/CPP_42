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
    if (list.size() <= 1)
        throw std::bad_exception();
    std::vector<int> sorted = list;
    std::sort(sorted.begin(), sorted.end());
    std::vector<int>::iterator first = sorted.begin();
    std::vector<int>::iterator last = sorted.end();
    return (*(--last) - *first);
}

void    Span::addNumber(int num)
{
    if (size <= list.size())
        throw std::bad_alloc();
    list.push_back(num);
}

