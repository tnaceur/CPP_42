#include "Serializer.hpp"
#include <sys/_types/_uintptr_t.h>
#include <sys/types.h>


Serializer::Serializer(){};

Serializer::~Serializer(){};

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    Data *value;
    value = reinterpret_cast<Data*>(raw);
    return value;
}
