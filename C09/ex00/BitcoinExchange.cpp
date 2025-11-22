#include "Date.hpp"
#include <map>

double closestTo(const std::map<Date, double>& map, const Date& _Date)
{
    std::map<Date,double>::const_iterator best = map.begin();

    for (std::map<Date,double>::const_iterator it = map.begin(); it != map.end(); ++it)
    {
        if (it->first <= _Date)
            best = it;
        else
            break;
    }
    if (_Date < best->first)
        throw std::runtime_error("ERROR: no value found");
    return best->second;
}

std::string trim(std::string val)
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

int inputFileProcess(char *filename, std::map<Date, double>& map)
{
    std::string line;
    std::string date;
    double amount;
    std::string val;
    size_t end;
    size_t check;
    size_t start;
    double rate;
    double result;
    std::fstream infile(filename);

    rate = 0;
    if (infile.fail())
    {
        std::cerr << "ERROR: cant open the input file" << std::endl;
        return 1;
    }
    end = 0;
    while(getline(infile, line))
    {
        check = line.find("date");
        if (check != std::string::npos)
            continue;
        start = 0;
        end = line.find('|');
        if (end == std::string::npos)
        {
            std::cerr << "ERROR: bad line format => " << line << std::endl;
            continue;
        }
        date = trim(line.substr(start, end - start));
        start = end + 1;
        val = trim(line.substr(start));
        std::stringstream ss(val);
        if (!(ss >> amount) || !(ss.eof()))
        {
            std::cerr << "ERROR: invalid value" << std::endl;
            continue;
        }
        try
        {
            Date _Date(date);
            if (amount < 0 || amount > 1000)
            {
                std::cerr << "ERROR: invalid amount" << std::endl;
                continue;
            }
            std::map<Date, double>::iterator  it = map.find(_Date);
            if (it != map.end())
                rate = it->second;
            else
                rate = closestTo(map, _Date);
            result = rate * amount;
            std::cout << date << " => " << amount << " = " << result << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            continue;
        }
    }
    return 0;
}

int main(int ac, char **av)
{
    std::fstream file;
    size_t end;
    size_t check;
    size_t start;
    std::string date;
    std::string val;
    double value;
    std::map<Date, double> map;

    if (ac < 2)
    {
        std::cerr << "ERROR: need a file to process" << std::endl;
        return 1;
    }
    start = 0;
    file.open("data.csv");
    if (file.fail())
    {
        std::cerr << "ERROR: cant open file" << std::endl;
        return 1;
    }
    std::string line;
    end = 0;
    while(getline(file, line))
    {
        check = line.find("date");
        if (check != std::string::npos)
            continue;
        start = 0;
        end = line.find(',');
        date = trim(line.substr(start, end - start));
        start = end + 1;
        val = trim(line.substr(start));
        std::stringstream ss(val);
        if (!(ss >> value) || !(ss.eof()))
        {
            // std::cerr << "ERROR: invalid value" << std::endl;
            continue;
        }
        Date _Date(date);
        map[_Date] = value;
    }
    if (inputFileProcess(av[1], map) == 1)
        return 1;
}