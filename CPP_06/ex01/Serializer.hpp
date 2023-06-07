#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>

struct Data{
    uintptr_t  x;
};

class Serializer
{
    Serializer();
    ~Serializer();
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
    
};

#endif