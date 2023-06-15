#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> lines;

    lines.push_back(9);
    lines.push_back(8);
    for (std::vector<int>::iterator it = lines.begin(); it != lines.end(); it++)
        std::cout << *it << std::endl;
}