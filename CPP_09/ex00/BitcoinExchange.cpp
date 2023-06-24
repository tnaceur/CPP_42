#include "BitcoinExchange.hpp"

void date_form(std::string& line)
{
    if (line[4] != '-' || line[7] != '-' || line.length() != 10)
        throw BAD_INPUT;
    
    int year = std::atoi(line.substr(0, 4).c_str());
    int month = std::atoi(line.substr(5, 2).c_str());
    int day = std::atoi(line.substr(8, 2).c_str());

    if (year < 2009 || year > 2023 || month < 1 || month > 12 || day < 1 || day > 31)
        throw BAD_INPUT;
    for (size_t i = 0; i < line.size(); i++)
    {
        if (i != 4 && i != 7 && !std::isdigit(line[i]))
            throw BAD_INPUT;
    }
}

void value_form(std::string& line)
{

    if (std::atof(line.c_str()) > 1000)
        throw "Error: too large a number.";
    if (std::atof(line.c_str()) < 0)
        throw "Error: not a positive number.";
    int point = 0;
    for (size_t i = 0; i < line.size(); i++)
    {
        if (line[i] == '+' && i == 0)
            i++;
        if (line[i] == '.')
            point++;
        else if (!std::isdigit(line[i]))
            throw BAD_INPUT;
    }
    if (point > 1)
        throw BAD_INPUT;
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
            try
            {
                std::string date = it->substr(0, it->find(" | "));
                std::string value = it->substr(it->find(" | ") + 3);
                if (value.empty())
                    throw BAD_INPUT;
                date_form(date);
                value_form(value);
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
            catch (const char* e)
            {
                std::string a = e;
                if (a == "Error: too large a number." || a == "Error: not a positive number.")
                    std::cout << a << std::endl;
                else
                    std::cout << a << *it << std::endl;
            }
        }
    }
}
