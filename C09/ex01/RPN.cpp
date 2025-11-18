#include "RPN.hpp"

RPN::RPN() : arr() {}

RPN::RPN(const RPN& obj) : arr(obj.arr) {}

RPN::RPN(char *_value)
{
    std::string newval(_value);
    value = newval;
}

RPN& RPN::operator=(const RPN& obj)
{
    if (this != & obj)
        arr = obj.arr;
    return *this;
}

RPN::~RPN() {}

void RPN::add(std::stack<int>& num_arr)
{
    int num1;
    int num2;
    
    if (num_arr.size() < 2)
        throw std::runtime_error("ERROR: invalid expression");
    else if (num_arr.size() >= 2)
    {
        num1 = num_arr.top();
        num_arr.pop();
        num2 = num_arr.top();
        num_arr.pop();
        num1 = num1 + num2;
        num_arr.push(num1);
    }
}

void RPN::divide(std::stack<int>& num_arr)
{
    int num1;
    int num2;
    
    if (num_arr.size() < 2)
    throw std::runtime_error("ERROR: invalid expression");
    else if (num_arr.size() >= 2)
    {
        num1 = num_arr.top();
        num_arr.pop();
        num2 = num_arr.top();
        if (num1 == 0) throw std::runtime_error("ERROR: division by zero");
        num_arr.pop();
        num1 = num2 / num1;
        num_arr.push(num1);
    }
}

void RPN::multiply(std::stack<int>& num_arr)
{
    int num1;
    int num2;
    
    if (num_arr.size() < 2)
        throw std::runtime_error("ERROR: invalid expression");
    else if (num_arr.size() >= 2)
    {
        num1 = num_arr.top();
        num_arr.pop();
        num2 = num_arr.top();
        num_arr.pop();
        num1 = num1 * num2;
        num_arr.push(num1);
    }
}

void RPN::subtract(std::stack<int>& num_arr)
{
    int num1;
    int num2;
    
    if (num_arr.size() < 2)
        throw std::runtime_error("ERROR: invalid expression");
    else if (num_arr.size() >= 2)
    {
        num1 = num_arr.top();
        num_arr.pop();
        num2 = num_arr.top();
        num_arr.pop();
        num1 = num2 - num1;
        num_arr.push(num1);
    }
}

void RPN::calcRPN()
{
    size_t end;
    size_t start;
    std::string token;
    std::stack<int> num_arr;

    start = 0;
    end = 0;
    while(end != std::string::npos)
    {
        end = value.find_first_of(" \t\n\v", start);
        std::string token = value.substr(start, end - start);
        if (!token.empty())
            arr.push(token);
        start = end + 1;
    }
    while (!arr.empty())
    {
        if (std::isdigit(arr.front()[0]))
        {
            if (arr.front().length() == 1)
                num_arr.push(atoi(arr.front().c_str()));
            else
                throw std::runtime_error("ERROR: number must contain only one digit");
        }
        else
        {
            if (arr.front() == "+")
                add(num_arr);
            else if (arr.front() == "-")
                subtract(num_arr);
            else if (arr.front() == "*")
                multiply(num_arr);
            else if (arr.front() == "/")
                divide(num_arr);
            else
                throw std::runtime_error("ERROR: invalid expression (do not start with an operator)");
        }
        arr.pop();
    }
    if (num_arr.size() > 1)
        throw std::runtime_error("ERROR: invalid expression");
    std::cout << num_arr.top() << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "ERROR: wrong number of arguments!" << std::endl;
        return 1;
    }
    RPN rpn(av[1]);
    try
    {
        rpn.calcRPN();
    }   
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}