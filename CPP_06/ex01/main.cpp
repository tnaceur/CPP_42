#include "Serializer.hpp"
#include <climits>

int main()
{
    Data *a = new Data;
    a->x = 200;
    uintptr_t s = Serializer::serialize(a);
    Data *b = Serializer::deserialize(s);
    std::cout << b->x << std::endl;
    delete a;
    return 1;
}
