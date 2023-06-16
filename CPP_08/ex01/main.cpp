#include "Span.hpp"
#include <algorithm>
#include <array>
#include <deque>
#include <list>

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}

// int main()
// {
//     try
//     {
//         Span sp = Span(5);
//         sp.addNumber(6);
//         sp.addNumber(9);
//         sp.addNumber(954);
//         sp.addNumber(5465);
//         sp.addNumber(556);
//         std::cout << "Longest Span is " << sp.longestSpan() << std::endl;
//         std::cout << "Shortest Span is " << sp.shortestSpan() << std::endl;
//         sp.PRINT_NUM();
//         std::cout << sp.shortestSpan() << std::endl;
//         std::cout << sp.longestSpan() << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << e.what() << std::endl;
//     }
//     return 0;
// }
