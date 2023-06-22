#include "RPN.hpp"
#include <cctype>
#include <stack>

void skip_space(std::string &str, int& i)
{
    while (str[i] && str[i] == ' ')
        i++;
}

void call_operator(std::stack<int>& rpn, int value1, int value2 , char op)
{
    if (op == '+')
        rpn.push(value2 + value1);
    else if (op == '-')
        rpn.push(value2 - value1);
    else if (op == '*')
        rpn.push(value2 * value1);
    else if (op == '/')
        rpn.push(value2 / value1);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return ((void)(std::cout << "Error: Wrong Number of Arguments\n"), 1);
    std::string args = av[1];
    std::stack<int> rpn;
    int value1, value2, num = 0, op = 0;
    (void)value1;
    (void)value2;
    for (int i = 0; i < static_cast<int>(args.size()); i++)
    {
        if (!std::isalnum(args[i]) && args[i] != ' ' && args[i] != '+' && args[i] != '-' && args[i] != '*' && args[i] != '/')
            return ((void)(std::cout << "Error\n"), 1);
        if (std::isalnum(args[i]))
            num++;
        else if (args[i] == '+' || args[i] == '-' || args[i] == '*' || args[i] == '/')
            op++;
    }
    if (num - op != 1)
        return ((void)(std::cout << "Error\n"), 1);
    for (int i = 0; i < static_cast<int>(args.size()); i++)
    {
        if (std::isalnum(args[i]))
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
    return 0;
}
