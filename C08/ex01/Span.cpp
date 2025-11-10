#include "Span.hpp"

Span::Span() :  N(0) {}

Span::Span(const Span &obj)
{
    this->N = obj.N;
    this->arr = obj.arr;
}

Span::Span(unsigned int n) : N(n) {}

Span& Span::operator=(const Span& obj)
{
    if (this != &obj)
    {
        this->N = obj.N;
        this->arr = obj.arr;
    }
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

void  Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (arr.size() + std::distance(begin, end) > N)
        throw std::runtime_error("you've exceeded the max number of elements you can add");
    else
        arr.insert(arr.end(), begin, end);
}

int Span::shortestSpan()
{
    if (arr.size() < 2)
        throw std::runtime_error("not enough elements to get the shortestspan");
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
    if (arr.size() < 2)
        throw std::runtime_error("not enough elements to get the longestspan");
    std::vector<int> temp = arr;
    std::vector<int>::iterator max = std::max_element(temp.begin(), temp.end());
    std::vector<int>::iterator min = std::min_element(temp.begin(), temp.end());
    return *max - *min;
}