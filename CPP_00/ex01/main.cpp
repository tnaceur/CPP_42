#include "PhoneBook.hpp"
#include <iomanip>

std::string    enter_data(std::string msg)
{
    std::string data;
    while (1)
    {
        std::cout << msg;
        std::getline(std::cin, data);
        if (std::cin.eof())
            exit(0);
        if (data.empty())
            std::cout << "Empty String" << std::endl;
        else
            break ;
    }
    return  (data);
}

void    print_data(std::string s)
{
    for (int i = 0; s[i] && i < 10; i++)
    {
        if (i == 9)
        {
            if (s.length() > 10)
            {
                std::cout << ".";
                break ;
            }
        }
        std::cout << s[i];
    }
}

void    Search(PhoneBook p, int j)
{

    std::cout << std::setw(9) << j << "|";
    for (int i = 1; i < 4; i++)
    {
        std::cout << std::setw((int)(10 - p.c_get(j, i).length()) + 1);
        print_data(p.c_get(j, i));
        if (i < 3)
            std::cout << "|";
    }
    std::cout << std::endl;
}

int main()
{
    PhoneBook   p;
    std::string line, data, i;
    int index, l, c_num;

    c_num = -1;
    while (1)
    {
        std::cout << "[ADD] || [SEARCH] || [EXIT] : ";
        std::getline(std::cin, line);
        if (std::cin.eof())
            exit(0);
        // ADD COMMAND
        if (line == "ADD")
        {
            p.c_set(index, 1, enter_data("Enter first name : "));
            p.c_set(index, 2, enter_data("Enter last name : "));
            p.c_set(index, 3, enter_data("Enter first nickname : "));
            p.c_set(index, 4, enter_data("Enter phone number : "));
            p.c_set(index, 5, enter_data("Enter your darkest secret : "));
            index++;
            if (index == 8)
            {
                l = index;
                index = 0;
            }
            else if (l != 8)
                l = index;
        }
        // END OF ADD COMMMAND
        // SEARCH COMMAND
        else if (line == "SEARCH")
        {
            if (l)
            {
                std::cout << "    index| fist name| last name|  nickname"<< std::endl;
                std::cout << "    --------------------------------------"<< std::endl;
                for (int j = 0; j < l; j++)
                    Search(p, j);
                std::cout << "    --------------------------------------"<< std::endl;
                std::cout << "    Contact N° : ";
                std::getline(std::cin, i);
                std::cout << "    --------------------------------------"<< std::endl;
                if (std::cin.eof())
                    exit(0);
				if (i.length() == 1)
					c_num = i[0] - 48;
                if (c_num >= 0 && c_num < l)
                {
                    std::cout << "First Name : " << p.c_get(c_num, 1) << std::endl;
                    std::cout << "Last Name : " << p.c_get(c_num, 2) << std::endl;
                    std::cout << "NickName : " << p.c_get(c_num, 3) << std::endl;
                    std::cout << "Phone N° : " << p.c_get(c_num, 4) << std::endl;
                    std::cout << "Darkest Secret : " << p.c_get(c_num, 5) << std::endl;
                }
                else if (i.length() > 1 || c_num <= 0 || c_num >= l)
                    std::cout << "Contact not found!!" << std::endl;
                c_num = -1;
            }
        }
        // END OF SEARCH COMMAND
        else if (line == "EXIT" || std::cin.eof())
            exit(0);
    }
}
