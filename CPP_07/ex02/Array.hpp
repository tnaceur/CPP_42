#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <iostream>
#include <exception>
#include <new>

template <typename T>
class Array {
    T *arr;
    unsigned int s;
public:
    /* Default constructor  */
    Array() : arr(NULL), s(0)
    {
    }

    /* Parametrized constructor  */
    Array(unsigned int n) : arr(new T[n]) , s(n)
    {
    }

    /* Copy constructor  */
    Array(const Array<T> &cp)
    {
        arr = NULL;
        *this = cp;
    }

    /*  Destructor  */
    ~Array()
    {
        if (arr)
            delete [] arr;
    }

    /* Copy assignement operator  */
    Array<T>& operator=(const Array<T> &array)
    {
        if (arr != NULL)
            delete [] arr;
        s = array.size();
        if (!s)
        {
            arr = NULL;
            throw std::bad_array_new_length();
        }
        arr = new T[s];
        for (unsigned int i = 0; i < array.size(); i++) 
            (*this)[i] = array[i];
        return (*this);
    }

    T &operator[](unsigned int n) const
    {
        if (n < 0 || n >= s)
            throw std::out_of_range("Array is out of range");
        return arr[n];
    }

    unsigned int size() const
    {
        return s;
    }
};

#endif
