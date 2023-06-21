#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <set>
#include <map>
#define DATA_FILE "data/data.csv"

// void check_date_format(std::vector<std::string> &lines, std::vector<std::string> &dates, std::vector<int> &values)
// {
//     for (std::vector<std::string>::iterator it = lines.begin(); it != lines.end(); it++)
//     {
        // std::string date = it->substr(0, it->find(" | "));
//         std::string value = it->substr(it->find(" | ") + 3);
//         if (date.length() != 10)
//             std::cout << "Error: date format is incorrect" << std::endl;
//         else
//         {
//             int year = std::atoi(date.substr(0, 4).c_str());
//             int month = std::atoi(date.substr(5, 2).c_str());
//             int day = std::atoi(date.substr(8, 2).c_str());
//             if (year < 1970 || year > 2023)
//                 dates.push_back("Error: year is incorrect");
//             else if (month < 1 || month > 12)
//                 dates.push_back("Error: month is incorrect");
//             else if (day < 1 || day > 31)
//                 dates.push_back("Error: day is incorrect");
//             else
//             {
//                 dates.push_back(date);
//                 values.push_back(std::atoi(value.c_str()));
//             }
//         }
//     }
// }

// void    print(std::vector<std::string>& dates, std::vector<int> &values)
// {
//     for (std::vector<std::string>::iterator it = dates.begin(); it != dates.end(); it++)
//         std::cout << *it << std::endl;
//     for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
//         std::cout << *it << std::endl;
// }

// void parse_date_value(std::vector<std::string> &lines)
// {
//     std::vector<std::string> dates;
//     std::vector<int> values;
//     check_date_format(lines, dates, values);
//     print(dates, values);
// }

void    get_value(std::vector<std::string> &lines, std::map<std::string, float>& data)
{
    for (std::vector<std::string>::iterator it = lines.begin(); it != lines.end(); it++)
    {
        std::string date = it->substr(0, it->find(" | "));
        std::string value = it->substr(it->find(" | ") + 3);
        if (date.length() != 10)
            std::cout << "Error: date format is incorrect" << std::endl;
        else
        {
            int year = std::atoi(date.substr(0, 4).c_str());
            int month = std::atoi(date.substr(5, 2).c_str());
            int day = std::atoi(date.substr(8, 2).c_str());

            if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
                std::cout << "Error: bad input => " << date << std::endl;
            else if (std::atof(value.c_str()) < 0)
                std::cout << "Error: not a positive number" << std::endl;
            else if (std::atof(value.c_str()) > std::numeric_limits<int>::max()
                || std::atof(value.c_str()) < std::numeric_limits<int>::min())
                std::cout << "Error: too large a number." << std::endl;
            else
            {
                if (data[date] == 0)
                {
                    // find the closest date
                    std::string closest_date;
                    for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); it++)
                    {
                        if (it->first < date)
                            closest_date = it->first;
                    }
                    std::cout << date << " => " << (std::atof(value.c_str()) * data[closest_date]) << std::endl;
                }
                else
                    std::cout << date << " => " << (std::atof(value.c_str()) * data[date]) << std::endl;
            }
        }
    }
}

int main(int ac, char **av)
{
    std::ifstream db(av[1]);
    std::map<std::string, float> data;
    std::vector<std::string> lines;
    std::ifstream d(DATA_FILE);

    if (ac != 2)
        return (void)(std::cout << "Error: invalid number of arguments" << std::endl), 1;
    if (db.is_open() && d.is_open())
    {
        std::string data_line, line;
        while (std::getline(d, data_line))
            data[data_line.substr(0, data_line.find(","))]
                = std::atof(data_line.substr(data_line.find(",") + 1).c_str());
        while (std::getline(db, line))
            lines.push_back(line);
        d.close();
        db.close();
    }
    else
        return (void)(std::cout << "Error: could not open file" << std::endl), 1;
    get_value(lines, data);
}
