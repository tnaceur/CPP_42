#include "PhoneBook.hpp"

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
            while (1)
            {
                std::cout << "Enter first name : " ;
                std::getline(std::cin, data);
                if (std::cin.eof())
                    exit(0);
                if (data.empty())
                    std::cout << "Empty String" << std::endl;
                else
                    break ;
            }
            p.c_set(index, 1, data);
            while (1)
            {
                std::cout << "Enter last name : " ;
                std::getline(std::cin, data);
                if (std::cin.eof())
                    exit(0);
                if (data.empty())
                    std::cout << "Empty String" << std::endl;
                else
                    break ;
            }
            p.c_set(index, 2, data);
            while (1)
            {
                std::cout << "Enter nickname : " ;
                std::getline(std::cin, data);
                if (std::cin.eof())
                    exit(0);
                if (data.empty())
                    std::cout << "Empty String" << std::endl;
                else
                    break ;
            }
            p.c_set(index, 3, data);
            while (1)
            {
                std::cout << "Enter phone number : " ;
                std::getline(std::cin, data);
                if (std::cin.eof())
                    exit(0);
                if (data.empty())
                    std::cout << "Empty String" << std::endl;
                else
                    break ;
            }
            p.c_set(index, 4, data);
            while (1)
            {
                std::cout << "Enter your darkest secret : " ;
                std::getline(std::cin, data);
                if (std::cin.eof())
                    exit(0);
                if (data.empty())
                    std::cout << "Empty String" << std::endl;
                else
                    break ;
            }
            p.c_set(index, 5, data);
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
                std::cout << "index| fist name| last name|  nickname"<< std::endl;
                std::cout << "--------------------------------------"<< std::endl;
                for (int j = 0; j < l; j++)
                {
                    std::cout << "    " << j << "|";
                    for (int a = 0; a < (int)(10 - p.c_get(j, 1).length()) && p.c_get(j, 1).length() < 10; a++)
                        std::cout << " ";
                    for (int i = 0; p.c_get(j, 1)[i] && i < 10; i++)
                    {
                        if (i == 9)
                        {
                            if (p.c_get(j, 1).length() > 10)
                            {
                                std::cout << ".";
                                break;
                            }
                        }
                        std::cout << p.c_get(j, 1)[i];
                    }
                    std::cout << "|";
                    for (int a = 0; a < (int)(10 - p.c_get(j, 2).length()) && p.c_get(j, 2).length() < 10; a++)
                        std::cout << " ";
                    for (int i = 0; p.c_get(j, 2)[i] && i < 10; i++)
                    {
                        if (i == 9)
                        {
                            if (p.c_get(j, 2).length() > 10)
                            {
                                std::cout << ".";
                                break ;
                            }
                        }
                        std::cout << p.c_get(j, 2)[i];
                    }
                    std::cout << "|";
                    for (int a = 0; a < (int)(10 - p.c_get(j, 3).length()) && p.c_get(j, 3).length() < 10; a++)
                        std::cout << " ";
                    for (int i = 0; p.c_get(j, 3)[i] && i < 10; i++)
                    {
                        if (i == 9)
                        {
                            if (p.c_get(j, 3).length() > 10)
                            {
                                std::cout << ".";
                                break;
                            }
                        }
                        std::cout << p.c_get(j, 3)[i];
                    }
                    std::cout << std::endl;
                }
                std::cout << "--------------------------------------"<< std::endl;
                std::cout << "Contact N° : ";
                std::getline(std::cin, i);
                std::cout << "--------------------------------------"<< std::endl;
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
