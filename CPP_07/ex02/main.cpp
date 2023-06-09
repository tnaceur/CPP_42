#include "Array.hpp"
#include <stdlib.h>

int main()
{
    try
    {
        Array<int> array(10);
        array[0] = 80;
        array[10] = 23;
        std::cout << array[0] << std::endl;
        std::cout << array[9] << std::endl;
        std::cout << array.size() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}