#include "easyfind.hpp"
#include <vector>

int main()
{
    std::cout << "========= Testing easyfind on a vector container =========\n" << std::endl;
    std::vector<int>  v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    
    std::cout << "========= Fail =========" << std::endl;
    try
    {
        easyfind(v, 0);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "========= Success =========" << std::endl;
    try
    {
        easyfind(v, 20);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}