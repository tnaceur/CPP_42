#include <iostream>
#include <fcntl.h>
#include <fstream>
#include <string>
#include <sstream>

int main(int ac, char **av)
{
    if (ac <= 1)
        return (0);
    std::ifstream file(av[1]);
    std::stringstream buffer;
    std::string s;
    buffer << file.rdbuf();
    s = buffer.str();
    std::cout << s << std::endl;
    file.close();
    return (0);
}
