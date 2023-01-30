#include "lib.hpp"
#include <unistd.h>
#include <stdlib.h>

int main()
{
    phonebook   p;
    std::string line, data;
    int index, l, i;

    while (1)
    {
        std::cout << "[ADD] || [SEARCH] || [EXIT] : ";
        std::getline(std::cin, line);
        if (std::cin.eof())
            exit(0);
        if (line == "ADD")
        {
            std::cout << "Enter first name : " ;
            std::getline(std::cin, data);
            p.c_set(index, 1, data);
            std::cout << "Enter last name : " ;
            std::getline(std::cin, data);
            p.c_set(index, 2, data);
            std::cout << "Enter nickname : " ;
            std::getline(std::cin, data);
            p.c_set(index, 3, data);
            std::cout << "Enter phone number : " ;
            std::getline(std::cin, data);
            p.c_set(index, 4, data);
            std::cout << "Enter your darkest secret : " ;
            std::getline(std::cin, data);
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
        else if (line == "SEARCH")
        {
            if (l)
            {
                std::cout << "index| fist name| last name|  nickname|  phone n°"<< std::endl;
                std::cout << "-------------------------------------------------"<< std::endl;
                for (int j = 0; j < l; j++)
                {
                    std::cout << "    " << j << "|";
                    for (int a = 0; a < (10 - p.c_get(j, 1).length()) && p.c_get(j, 1).length() < 10; a++)
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
                    for (int a = 0; a < (10 - p.c_get(j, 2).length()) && p.c_get(j, 2).length() < 10; a++)
                        std::cout << " ";
                    for (int i = 0; p.c_get(j, 2)[i] && i < 10; i++)
                    {
                        if (i == 9)
                        {
                            if (p.c_get(j, 2).length() > 10)
                            {
                                std::cout << ".";
                                break;
                            }
                        }
                        std::cout << p.c_get(j, 2)[i];
                    }
                    std::cout << "|";
                    for (int a = 0; a < (10 - p.c_get(j, 3).length()) && p.c_get(j, 3).length() < 10; a++)
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
                    std::cout << "|";
                    for (int a = 0; a < (10 - p.c_get(j, 4).length()) && p.c_get(j, 4).length() < 10; a++)
                        std::cout << " ";
                    for (int i = 0; p.c_get(j, 4)[i] && i < 10; i++)
                    {
                        if (i == 9)
                        {
                            if (p.c_get(j, 4).length() > 10)
                            {
                                std::cout << ".";
                                break;
                            }
                        }
                        std::cout << p.c_get(j, 4)[i];
                    }
                    std::cout << std::endl;
                }
                std::cout << "-------------------------------------------------"<< std::endl;
                std::cout << "Contact N° : ";
                std::cin >> i;
                if (i < 9)
                {
                    std::cout << "First Name : " << p.c_get(i, 1) << std::endl;
                    std::cout << "Last Name : " << p.c_get(i, 2) << std::endl;
                    std::cout << "NickName : " << p.c_get(i, 3) << std::endl;
                    std::cout << "Phone N° : " << p.c_get(i, 4) << std::endl;
                    std::cout << "Darkest Secret : " << p.c_get(i, 5) << std::endl;
                }
                else if (std::cin.fail())
                {
                    std::cout<< "Error!!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                }
                else
                    std::cout << "Contact not found!!" << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        }
        else if (line == "EXIT" || std::cin.eof())
            exit(0);
    }
}
