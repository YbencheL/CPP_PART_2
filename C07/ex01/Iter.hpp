#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template  <typename T, typename FUNC>
void iter(T arr[], int size, FUNC func)
{
    for (int i = 0; i < size; i++)
        func(arr[i]);
};

#endif