#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat a("yass", 20);
    try
    {
        a.decrementGrade();
        std::cout << a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}