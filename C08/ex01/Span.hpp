#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <limits>
#include <algorithm>


class Span
{
    private:

        unsigned int N;
        std::vector<int> arr;
    
    public:

        Span();
        Span(unsigned int n);
        Span(const Span& obj);
        Span& operator=(const Span& obj);
        void addNumber(int num);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
        ~Span();
};

#endif