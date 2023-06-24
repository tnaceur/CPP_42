/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <tnaceur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:07:04 by tnaceur           #+#    #+#             */
/*   Updated: 2023/06/24 17:14:03 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return ((void)(std::cout << "Error: Wrong Number of Arguments\n"), 1);
    try
    {
        std::string args = av[1];
        std::stack<int> rpn;
        int value1, value2, num = 0, op = 0;
        for (int i = 0; i < static_cast<int>(args.size()); i++)
        {
            if (!std::isdigit(args[i]) && args[i] != ' ' && args[i] != '+' && args[i] != '-' && args[i] != '*' && args[i] != '/')
                return ((void)(std::cout << "Error\n"), 1);
            if (std::isdigit(args[i]))
                num++;
            else if (args[i] == '+' || args[i] == '-' || args[i] == '*' || args[i] == '/')
                op++;
        }
        if (num - op != 1)
            return ((void)(std::cout << "Error\n"), 1);
        for (int i = 0; i < static_cast<int>(args.size()); i++)
        {
            if (std::isdigit(args[i]))
                rpn.push(args[i] - '0');
            else if (args[i] == '+' || args[i] == '-' || args[i] == '*' || args[i] == '/')
            {
                if (rpn.size() < 2)
                    return ((void)(std::cout << "Error\n"), 1);
                value1 = rpn.top();
                rpn.pop();
                value2 = rpn.top();
                rpn.pop();
                call_operator(rpn, value1, value2, args[i]);
            }
        }
        std::cout << rpn.top() << std::endl;
    }
    catch (const char* e)
    {
        std::cout << e << std::endl;
    }
    return 0;
}
