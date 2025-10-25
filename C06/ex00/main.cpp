#include "ScalarConverter.hpp"



int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Give an argument to cast!!!" << std::endl;
        return 1;
    }
    std::cout << "======================\n";
    ScalarConverter::convert(av[1]);
    std::cout << "======================\n";
}