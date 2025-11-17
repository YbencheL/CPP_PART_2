#include "PmergeMe.hpp"
#include <ctime>

PmergeMe::PmergeMe() : vec(0), deq(0) {}

PmergeMe::PmergeMe(const PmergeMe& obj) : vec(obj.vec), deq(obj.deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
    if (this != & obj)
    {
        vec = obj.vec;
        deq = obj.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void merge_Sort(std::vector<int>& verr)
{
    int length = verr.size();
    if (length <= 1) return;

    int mid = length / 2;
    std::vector<int> left(verr.begin(), verr.begin() + mid);
    std::vector<int> right(verr.begin() + mid, verr.end());

    merge_Sort(left);
    merge_Sort(right);
    merge(left, right, verr);
}


void merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& verr)
{
    int leftS = verr.size() / 2;
    int rightS = verr.size() - leftS;
    int i = 0, l = 0, r = 0;

    while(l < leftS && r < rightS)
    {
        if (left[l] < right[r])
        {
            verr[i] = left[l];
            l++;
            i++;
        }
        else
        {
            verr[i] = right[r];
            r++;
            i++;
        }
    }
    while(l < leftS)
    {
        verr[i] = left[l];
        i++;
        l++;
    }
    while(r < rightS)
    {
        verr[i] = right[r];
        i++;
        r++;
    }
}

size_t Bisearch(std::vector<int>& win, int target)
{
    size_t low_half = 0;
    size_t middle = 0;
    size_t high_half = win.size() - 1;

    while(low_half <= high_half)
    {
        middle = low_half + (high_half - low_half) / 2;
        
        if (target <= win[middle])
        {
            if (middle == 0)
                break;
            high_half = middle - 1;
        }
        else
            low_half = middle + 1;
    }
    return low_half;
}

size_t Jacobsthal(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

template <typename C>
void sortThem(C& c)
{
    if (c.empty()) return;

    std::vector<int> winner;
    std::vector<int> loser;
    int struggle = 0;

    if (c.size() % 2 != 0) {
        struggle = c.back();
        c.pop_back();
    }

    for (size_t i = 0; i + 1 < c.size(); i += 2) {
        int a = c[i];
        int b = c[i + 1];
        winner.push_back(std::max(a, b));
        loser.push_back(std::min(a, b));
    }

    merge_Sort(winner);
    size_t j = 0;
    size_t i = 0;
    while (Jacobsthal(i) < loser.size())
    {
        j = Jacobsthal(i);
        if (j >= loser.size()) 
            break;
        int target = loser[j];
        loser.erase(loser.begin() + j);
        size_t index = Bisearch(winner, target);
        winner.insert(winner.begin() + index, target);
        i++;
    }
    for (size_t k = 0; k < loser.size(); k++)
    {
        int target = loser[k];
        size_t index = Bisearch(winner, target);
        winner.insert(winner.begin() + index, target);
    }
    if (struggle) {
        size_t index = Bisearch(winner, struggle);
        winner.insert(winner.begin() + index, struggle);
    }
    c.clear();
    std::copy(winner.begin(), winner.end(), std::back_inserter(c)); 
}


std::string PmergeMe::trim(std::string val)
{
    size_t s = val.find_first_not_of(" \t\n\r");
    if (s == std::string::npos)
    {
        val = "";
        return val;
    }
    size_t e = val.find_last_not_of(" \t\n\r");
    val = val.substr(s, e + 1);
    return val;
}

void PmergeMe::parseToV(std::string arr)
{
    size_t end;
    size_t start;
    std::string value;
    int num;

    end = 0;
    start = 0;
    while(end != std::string::npos)
    {
        end = arr.find(" ", start);
        value = trim(arr.substr(start, end - start));
        std::stringstream ss(value);
        if (!value.empty())
        {
            if (!(ss >> num) || !(ss.eof()) || num < 0)
                throw std::runtime_error("ERROR: invalid value");
            else
                vec.push_back(num);
        }
        start = end + 1;
    }
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    clock_t startT = clock();
    sortThem(vec);
    clock_t endT = clock();
    double elapsed_micros = double(endT - startT) * 1000000 / CLOCKS_PER_SEC;
    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << std::fixed << vec.size() << " elements with std::vector : " << elapsed_micros << " us\n";
}

void PmergeMe::parseToD(std::string arr)
{
    size_t end;
    size_t start;
    std::string value;
    int num;

    end = 0;
    start = 0;
    while(end != std::string::npos)
    {
        end = arr.find(" ", start);
        value = trim(arr.substr(start, end - start));
        std::stringstream ss(value);
        if (!value.empty())
        {
            if (!(ss >> num) || !(ss.eof()) || num < 0)
                throw std::runtime_error("ERROR: invalid value");
            else
                deq.push_back(num);
        }
        start = end + 1;
    }
    clock_t startT = clock();
    sortThem(deq);
    clock_t endT = clock();
    double elapsed_micros = double(endT - startT) * 1000000 / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << std::fixed << deq.size() << " elements with std::deque : " << elapsed_micros << " us\n";
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "ERROR: wrong number of arguments" << std::endl;
        return 1;
    }

    PmergeMe d;

    try
    {
        d.parseToV(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    d.parseToD(av[1]);
}