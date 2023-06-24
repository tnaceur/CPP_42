#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <sys/_types/_size_t.h>
#include <vector>
#include <set>
#include <map>

#define DATA_FILE "data/data.csv"


bool date_form(std::string& line);
bool value_form(std::string& line);
void    get_value(std::vector<std::string> &lines, std::map<std::string, float>& data);

#endif