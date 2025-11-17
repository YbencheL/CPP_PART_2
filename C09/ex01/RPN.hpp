#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <string>
#include <queue>

class RPN
{
    private:

        std::string value;
        std::queue<std::string> arr;

    public:

        RPN();
        RPN(const RPN& obj);
        RPN(char *_value);
        RPN& operator=(const RPN& obj);
        void calcRPN();
        void add(std::stack<int>& num_arr);
        void divide(std::stack<int>& num_arr);
        void multiply(std::stack<int>& num_arr);
        void subtract(std::stack<int>& num_arr);
        ~RPN();
};

#endif