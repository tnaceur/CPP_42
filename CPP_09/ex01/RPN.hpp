#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <cctype>
#include <exception>
#include <stack>

void call_operator(std::stack<int>& rpn, int value1, int value2 , char op);

#endif