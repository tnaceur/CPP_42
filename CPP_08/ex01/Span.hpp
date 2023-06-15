#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>

class	Span
{
    unsigned int size;
    std::vector<int> list;
    public:
        Span (unsigned int N);
        Span ();
        ~Span ();
        Span (const Span&);
        Span &operator=(const Span&);
        void addNumber(int num);
        int shortestSpan();
        int longestSpan();
        template<typename T>
        void addNumbers(T container)
        {
            if (list.size() + container.size() > size)
                throw std::bad_alloc();
            list.insert(list.end(), container.begin(), container.end());
        }
        void PRINT_NUM()
        {
            for (std::vector<int>::iterator i = list.begin(); i != list.end(); i++)
                std::cout << *i << std::endl;
        }
};

#endif
