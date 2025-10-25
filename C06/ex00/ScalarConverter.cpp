#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& obj) {(void)obj;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj) 
{
    (void)obj;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::to_char(double conv)
{
    char c;

    c = static_cast<char>(conv);
    if (std::isnan(conv) || std::isinf(conv))
        std::cout << "char: Impossible" << std::endl;
    else if (c < 32 || c > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << "'" << c << "'" << std::endl;
}

void ScalarConverter::to_int(double conv)
{
    int c;

    c = static_cast<int>(conv);
    if (std::isnan(conv) || std::isinf(conv))
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << c << std::endl;
}

void ScalarConverter::to_float(double conv)
{
    float c;

    c = static_cast<float>(conv);
    std::cout << "float: " << std::fixed << std::setprecision(1) << c << "f" << std::endl;
}

void ScalarConverter::to_double(double conv)
{
    std::cout << "double: " << std::fixed << std::setprecision(1) << conv << std::endl;
}

void ScalarConverter::convert(std::string conv)
{
    double convi;

    convi = atof(conv.c_str());
    to_char(convi);
    to_int(convi);
    to_float(convi);
    to_double(convi);
}