#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("yass", 20);
        a.decrementGrade();
        std::cout << a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat v("vass", 1);
        v.incrementGrade();
        std::cout << v << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b("bass", 150);
        b.decrementGrade();
        std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}