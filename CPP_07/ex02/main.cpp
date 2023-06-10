#include "Array.hpp"
#include <cstdlib>
#include <stdlib.h>

int main()
{
    try
    {
        Array<int> a(11);

        for (int i = 0; i < (int)a.size(); i++)
            a[i] = i;
        for (int i = 0; i < (int)a.size(); i++)
            std::cout << a[i] << std::endl;
        a[12] = 0;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 1;
}
