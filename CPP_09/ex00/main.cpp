#include "BitcoinExchange.hpp"

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
