#include "RPN.hpp"


void call_operator(std::stack<int>& rpn, int value1, int value2 , char op)
{
    if (op == '+')
        rpn.push(value2 + value1);
    else if (op == '-')
        rpn.push(value2 - value1);
    else if (op == '*')
        rpn.push(value2 * value1);
    else if (op == '/')
    {
        if (value1 == 0)
            throw "Number Cannot be devided by 0";
        rpn.push(value2 / value1);
    }
}
