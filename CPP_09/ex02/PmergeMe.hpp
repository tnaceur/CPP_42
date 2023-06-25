#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <deque>
#include <iostream>
#include <iterator>
#include <ostream>
#include <utility>
#include <sstream>
#include <sys/time.h>
#include <vector>
#include <list>

#define WRONG_ARG "Error: Wrong number of arguments"
#define NEGATIVE_NUM "Error: Negative Number."
#define INVALID_INPUT "Invalid input."

void    deque_sort(int ac, char **av, std::deque<int>& after, double& time);
void    list_sort(int ac, char **av, std::list<int>& before, double& time);
void    int_convert(std::string s, int& num);
void    print(std::list<int> &smallest);
void    print(std::deque<int> &smallest);


#endif