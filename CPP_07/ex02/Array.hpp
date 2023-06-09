#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
    T *arr;
    unsigned int s;
public:
    Array() : arr(NULL), s(0) {}
    Array(unsigned int n) : arr(new T[n]) , s(n) {}
    Array(const Array<T> &array) : arr(array), s(array.size()) {}
    T& operator=(const Array<T> &array)
    {
        if (arr != NULL)
            delete [] arr;
        arr = new T[array.size()];
        for (unsigned int i = 0; i < array.size(); i++) 
            arr[i] = array[i];
        return *this;
    }
    unsigned int size() const
    {
        return s;
    }
    T& operator[](unsigned int n)
    {
        if (n < 0 || n >= s)
            throw std::out_of_range("Array is out of range");
        return arr[n];
    }
};

#endif
