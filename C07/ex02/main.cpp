#include "Array.hpp"
#include <iomanip>

int main()
{
    try
    {
        std::cout << "=== Default constructor ===" << std::endl;
        Array<int> const a;
        std::cout << "Size: " << a.size() << std::endl;

        std::cout << "\n=== Param constructor ===" << std::endl;
        Array<int> b(5);
        std::cout << "Size: " << b.size() << std::endl;
        for (unsigned int i = 0; i < b.size(); i++)
        {
            b[i] = i;
            std::cout << "b["<< i << "]: ";
            std::cout << b[i] << std::endl;
        }
        std::cout << "\n=== Copy constructor ===" << std::endl;
        Array<int> c(b);
        std::cout << "b[4]: " << b[4] << " | c[4]: " << c[4] << std::endl;
        b[3] = 333;
        std::cout << "b[3]: " << b[3] << " | c[3]: " << c[3] << std::endl;

        std::cout << "\n=== Assignment operator ===" << std::endl;
        Array<int> g;
        g = b;
        std::cout << "g[1]: " << g[1] << " | b[1]: " << b[1] << std::endl;
        g[2] = 222;
        std::cout << "g[2]: " << g[2] << " | b[2]: " << b[2] << std::endl;
        
        std::cout << "\n=== Testing outher types ===" << std::endl;
        Array<double> h(3);
        h[0] = 0.0;
        h[1] = 1.0;
        h[2] = 2.0;
        std::cout << "h[0]: " << std::fixed << std::setprecision(1) << h[0] << std::endl;
        std::cout << "h[1]: " << h[1] << std::endl;
        std::cout << "h[2]: " << h[2] << std::endl;

        std::cout << "\n=== Out of range test ===" << std::endl;
        std::cout << b[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}