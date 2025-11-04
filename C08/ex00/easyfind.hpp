#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>

template <typename T>
void easyfind(T& arr, int s_index)
{
    // for (typename T::iterator it = arr.begin(); it != arr.end(); it++)
    // {
    //     if (*it == s_index)
    //     {
    //         std::cout << *it << " " << std::endl;
    //         return ;
    //     }
    // }
    typename T::iterator it = find(arr.begin(), arr.end(), s_index);
    if (it != arr.end())
    {
        std::cout << *it << " " << std::endl;
        return;
    }else
        throw std::runtime_error("Index was not found");
}

#endif