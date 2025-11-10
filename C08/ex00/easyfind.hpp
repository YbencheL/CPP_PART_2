#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>

template <typename T>
void easyfind(T& arr, int s_index)
{
    typename T::iterator it = find(arr.begin(), arr.end(), s_index);
    if (it != arr.end())
    {
        std::cout << *it << std::endl;
        return;
    }else
        throw std::runtime_error("Index was not found");
}

#endif