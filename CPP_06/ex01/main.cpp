#include "Serializer.hpp"
#include <climits>

int main()
{
    Data a;
    a = *Serializer::deserialize(300);
    int x = Serializer::serialize(&a);
    std::cout << x << std::endl;
    return 1;
}
