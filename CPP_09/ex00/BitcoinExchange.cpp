#include "BitcoinExchange.hpp"

bool date_form(std::string& line)
{
    if (line[4] != '-' || line[7] != '-' || line.length() != 10)
        return (void)(std::cout << "Error: bad input => " << line << std::endl), false;
    
    int year = std::atoi(line.substr(0, 4).c_str());
    int month = std::atoi(line.substr(5, 2).c_str());
    int day = std::atoi(line.substr(8, 2).c_str());

    if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
        return (void)(std::cout << "Error: bad input => " << line << std::endl), false;
    for (size_t i = 0; i < line.size(); i++)
    {
        if (i != 4 && i != 7 && !std::isdigit(line[i]))
            return (void)(std::cout << "Error: bad input => " << line << std::endl), false;
    }
    return true;
}

bool value_form(std::string& line)
{

    if (std::atof(line.c_str()) >= 1000)
        return (void)(std::cout << "Error: too large a number." << std::endl), false;
    if (std::atof(line.c_str()) < 0)
        return (void)(std::cout << "Error: not a positive number" << std::endl), false;
    int point = 0;
    for (size_t i = 0; i < line.size(); i++)
    {
        if (line[i] == '+' && i == 0)
            i++;
        if (line[i] == '.')
            point++;
        else if (!std::isdigit(line[i]))
            return (void)(std::cout << "Error: not a number" << std::endl), false;
    }
    if (point > 1)
        return (void)(std::cout << "Error: not a number" << std::endl), false;
    return true;
}

void    get_value(std::vector<std::string> &lines, std::map<std::string, float>& data)
{
    if (lines[0] != "date | value")
        return (void)(std::cout << "Error: First line" << std::endl);
    std::vector<std::string>::iterator it = lines.begin();
    it++;
    for (; it != lines.end(); it++)
    {
        if (!it->empty())
        {
            std::string date = it->substr(0, it->find(" | "));
            std::string value = it->substr(it->find(" | ") + 3);
            std::cout<< "\"" << date << "\""  + value + "\"" << "\"" << std::endl;
            if (date.c_str() + 2 == value.c_str())
                std::cout << "Error: bad input => " << date << std::endl;
            else if (value.empty())
                std::cout << "Error: Syntax invalid. No value" << std::endl;
            else if (!date_form(date) || !value_form(value))
               ;
            else
            {
                if (data[date] == 0)
                {
                    std::map<std::string, float>::iterator exchange = data.lower_bound(date);
                    exchange--;
                    std::cout << date << " => " << value << " = " << (std::atof(value.c_str()) * exchange->second) << std::endl;
                }
                else
                {
                    std::map<std::string, float>::iterator exchange = data.lower_bound(date);
                    std::cout << date << " => " << value << " = " << (std::atof(value.c_str()) * exchange->second) << std::endl;
                }
            }
        }
    }
}
