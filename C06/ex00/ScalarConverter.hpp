#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip> 


class ScalarConverter
{
  private:
  
    ScalarConverter();
    ScalarConverter(const ScalarConverter& obj);
    ScalarConverter& operator=(const ScalarConverter& obj);
    static void to_double(double conv);
    static void to_float(double conv);
    static void to_int(double conv);
    static void to_char(double conv);
    ~ScalarConverter();

    public:
    
    static void convert(std::string conv);
};

#endif