#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <sstream>

class Date
{
    private:

        int year;
        int month;
        int day;
        static void DateValidation(int year, int month, int day);

    public:

        Date();
        Date(const Date& obj);
        Date(const std::string& date);
        Date& operator=(const Date& obj);
        bool operator<(const Date& obj) const;
        bool operator<=(const Date& obj) const;
        bool operator==(const Date& other) const;
        ~Date();
};

#endif