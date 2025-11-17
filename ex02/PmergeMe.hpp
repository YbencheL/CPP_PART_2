#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <deque>
#include <sstream>
#include <algorithm>


class PmergeMe
{
    private:

        std::vector<int> vec;
        std::deque<int> deq;

    public:

        PmergeMe();
        PmergeMe(const PmergeMe& obj);
        PmergeMe& operator=(const PmergeMe& obj);
        void parseToV(std::string arr);
        void parseToD(std::string arr);
        std::string trim(std::string val);
        ~PmergeMe();
    };
    
size_t Bisearch(std::vector<int>& win, int target);
void merge_Sort(std::vector<int>& verr);
void merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& verr);

#endif