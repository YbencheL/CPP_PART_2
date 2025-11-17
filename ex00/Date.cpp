#include "Date.hpp"

Date::Date() : year(2026), month(01), day(01) {}

Date::Date(const Date& obj)
{
    year = obj.year;
    month = obj.month;
    day = obj.day;
}

Date& Date::operator=(const Date& obj)
{
    if (this != &obj)
    {
        year = obj.year;
        month = obj.month;
        day = obj.day;
    }
    return *this;
}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::operator==(const Date& other) const
{
    return (year == other.year && month == other.month && day == other.day);
}


bool Date::operator<=(const Date& other) const {
    return *this < other || *this == other;
}


Date::~Date() {}

Date::Date(const std::string& date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        throw std::runtime_error("ERROR: invalid date format");

    int y = atoi(date.substr(0,4).c_str());
    int m = atoi(date.substr(5,2).c_str());
    int d = atoi(date.substr(8,2).c_str());

    DateValidation(y, m, d);

    this->year  = y;
    this->month = m;
    this->day   = d;
}


void Date::DateValidation(int year, int month, int day)
{
    if (month < 1 || month > 12)
    {
        throw std::runtime_error("ERROR: invalid month");
    }
    if (month == 2)
    {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        {
            if (day > 29 || day < 1)
            {
                throw std::runtime_error("ERROR: invalid day (This year is a leap year btw :)");
            }
        }else if (day > 28 || day < 1)
        {
            throw std::runtime_error("ERROR: invalid day");
        }
    }
    if ((month == 1) || (month == 3) || (month == 5) || (month == 7) ||
        (month == 8) || (month == 10) || (month == 12))
    {
        if (day > 31 || day < 1)
        {
            throw std::runtime_error("ERROR: invalid day");
        }
    }
    else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
    {
        if (day > 30 || day < 1)
        {
            throw std::runtime_error("ERROR: invalid day");
        }
    }
}