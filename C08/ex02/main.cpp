#include "MutantStack.hpp"
#include <algorithm>

int main()
{
    std::cout << "========= Subject test =========" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\n========= my own tests const iterator =========" << std::endl;
    
    MutantStack<int> mcstack;
    for (int i = 0; i < 100; i++)
        mcstack.push(i);
    std::cout << mcstack.size() << std::endl;
    mcstack.pop();
    std::cout << mcstack.size() << std::endl;
    int max = 0;
    MutantStack<int>::const_iterator it_next;
    for (MutantStack<int>::const_iterator it = mcstack.cbegin(); it != mcstack.cend(); it++)
    {
        it_next = it + 1;
        if (*it < *it_next)
        max = *it_next;
    }
    std::cout << max << std::endl;
    mcstack.push(100);
    std::cout << mcstack.size() << std::endl;

    std::cout << "\n========= reverse iterator =========" << std::endl;
    MutantStack<int> mg;
    for (int i = 1; i <= 10; i++)
        mg.push(i);
    std::cout << "Size: " << mg.size() << std::endl;
    std::cout << "Reverse iteration: ";
    for (MutantStack<int>::reverse_iterator rit = mg.rbegin(); rit != mg.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;
        
    std::cout << "\n========= const reverse iterator =========" << std::endl;
    MutantStack<int> cmg;
    for (int i = 1; i <= 5; i++)
        cmg.push(i);
    std::cout << "Const reverse iteration: ";
    for (MutantStack<int>::const_reverse_iterator crit = cmg.crbegin(); crit != cmg.crend(); ++crit)
        std::cout << *crit << " ";
    std::cout << std::endl;
    int sum = 0;
    for (MutantStack<int>::reverse_iterator rit = cmg.rbegin(); rit != cmg.rend(); ++rit)
        sum += *rit;
    std::cout << "Sum (reverse): " << sum << std::endl;

    return 0;
}