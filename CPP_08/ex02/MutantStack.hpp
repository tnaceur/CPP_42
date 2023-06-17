#pragma once

#include <iostream>
#include <stack>

template <typename T, class container=std::deque<T> >
class MutantStack : public std::stack<T, container>
{
    public:
        MutantStack(){}
        ~MutantStack(){}
        MutantStack(const MutantStack &cp)
        {
            *this = cp;
        }
        typedef typename container::iterator iterator;
        iterator begin()
        {
            return this->c.begin();
        }
        iterator end()
        {
            return this->c.end();
        }
};
