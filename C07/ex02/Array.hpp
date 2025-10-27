#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array
{
    private:

        T* arr;
        unsigned int len;

    public:

        Array() : arr(NULL), len(0) {}
        
        Array(const Array& obj)
        {
            arr = new T[obj.len];
            for (unsigned int i = 0; i < obj.len; i++)
                arr[i] = obj.arr[i];
            len = obj.len;
        }
        Array(unsigned int n)
        {
            arr = new T[n];
            len = n;
        }
        ~Array()
        {
            delete []arr;
        }
        Array& operator=(const Array& obj)
        {
            if (this != &obj)
            {
                len = obj.len;
                arr = new T[obj.len];
                for (unsigned int i = 0; i < obj.len; i++)
                    arr[i] = obj.arr[i];
            }
            return *this;
        }
        T& operator[](unsigned int index)
        {
            if (index >= len)
                throw std::out_of_range("Index out of bounds");
            return arr[index];
        }
        const T& operator[](unsigned int index) const 
        {
            if (index >= len)
                throw std::out_of_range("Index out of bounds");
            return arr[index];
        }
        unsigned int size() const 
        {
            return len;
        }
};

#endif

