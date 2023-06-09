#include "iter.hpp"
#include <string>

template<typename T>
void print(T& a)
{
    std::cout << a << std::endl;
}

int main() {
    std::string arr[] = {"taha", "naceur", "test"};

    iter(arr, 3, print<std::string>);
    return 0;
}
