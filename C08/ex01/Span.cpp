#include "Span.hpp"

Span::Span() :  N(0) {}

Span::Span(const Span &obj)
{
    N = obj.N;
}

Span::Span(unsigned int n) : N(n)
{
}

Span& Span::operator=(const Span& obj)
{
    if (this != &obj)
        N = obj.N;
    return *this;
}

Span::~Span() {}

void  Span::addNumber(int num)
{
    if (arr.size() < N)
        arr.push_back(num);
    else
        throw std::runtime_error("you've exceeded the max number of elements you can add");
}

int Span::shortestSpan()
{
    std::vector<int> temp = arr;
    int min = std::numeric_limits<int>::max(); 
    int diff = 0; 
    std::vector<int>::iterator next_it;
    std::sort(temp.begin(), temp.end());
    for(std::vector<int>::iterator it = temp.begin(); it != temp.end() - 1; it++)
    {
        next_it = it + 1;
        diff = *next_it - *it;
        if (diff < min)
            min = diff;
    }
    return min;
}

int Span::longestSpan()
{
    std::vector<int> temp = arr;
    std::vector<int>::iterator max = std::max_element(temp.begin(), temp.end());
    std::vector<int>::iterator min = std::min_element(temp.begin(), temp.end());
    return *max - *min;
}