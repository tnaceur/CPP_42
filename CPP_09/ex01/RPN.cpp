#include "RPN.hpp"

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
