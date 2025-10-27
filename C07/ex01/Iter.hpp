#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template  <typename T> void iter(T arr[], int size, void (*func)(T&))
{
    for (int i = 0; i < size; i++)
    {
        func(arr[i]);
    }
};

template  <typename T> void iter(T arr[], int size, void (*func)(const T&))
{
    for (int i = 0; i < size; i++)
    {
        func(arr[i]);
    }
};

#endif