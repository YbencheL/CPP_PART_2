#include "base_func.hpp"

int main()
{
    Base* p1 = generate();
    identify(p1);
    std::cout << "=========================\n";
    Base* p2 = generate();
    identify(*p2);
    delete p1;
    delete p2;
    return 0;
}