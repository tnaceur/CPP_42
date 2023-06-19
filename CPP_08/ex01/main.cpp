#include "Span.hpp"
#include <algorithm>
#include <array>
#include <deque>
#include <list>
#include <vector>

int main()
{
    try 
    {
        int N = 10500;
        Span sp = Span(N);
        std::vector<int> points;
        for (int i = 1; i <= N ; i++)
        {
            points.push_back(i);
        }
        sp.addNumbers(points);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
