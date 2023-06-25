#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac == 1)
            throw WRONG_ARG;
        std::list<int> before;
        double v_time, d_time;
        list_sort(ac, av, before, v_time);
        std::cout << "Before: ";
        print(before);
        std::deque<int> after;
        deque_sort(ac, av, after, d_time);
        std::cout << "After:  ";
        print(after);
        std::cout << "Time to process a range of " << before.size() <<  " elements with std::list is : "
            << v_time << " us" << std::endl;
        std::cout << "Time to process a range of " << before.size() <<  " elements with std::deque is : "
            << d_time << " us" << std::endl;
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
    }
    return 0;
}
