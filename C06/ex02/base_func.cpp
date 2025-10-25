#include "base_func.hpp"

Base*   generate(void)
{
    srand(time(0));
    int randomIndx = rand() % 3;

    switch (randomIndx)
    {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            return NULL;
    }
}

void    identify(Base* p)
{
    if (A* p1 = dynamic_cast<A*>(p))
        std::cout << "The type of the object pointed to by p is A" << std::endl;
    if (B* p2 = dynamic_cast<B*>(p))
        std::cout << "The type of the object pointed to by p is B" << std::endl;
    if (C* p3 = dynamic_cast<C*>(p))
        std::cout << "The type of the object pointed to by p is C" << std::endl;
    else
        std::cout << "Not of any type" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "The type of the object pointed to by p is A" << std::endl;
        return ;
    }
    catch(...)
    {
        // std::cout << "Not of type A" << std::endl;
    }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "The type of the object pointed to by p is B" << std::endl;
        return;
    }
    catch(...)
    {
        // std::cout << "Not of type B" << std::endl;
    }
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "The type of the object pointed to by p is C" << std::endl;
        return ;
    }
    catch(...)
    {
        // std::cout << "Not of type C" << std::endl;
    }
    std::cout << "Not of any type" << std::endl;
}
