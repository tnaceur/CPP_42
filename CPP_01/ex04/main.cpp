#include "main.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
        return (std::cerr << "Wrong Arguments" << std::endl, 1);
    std::string f = av[1], to_find = av[2] , to_repl = av[3], s;
    char c;
    std::ifstream file(f);
    if (!file.is_open())
        return (std::cerr << "File Error" << std::endl, 1);
    if (to_find.empty())
        return (std::cerr << "Empty String To Search" << std::endl, 1);
    while (file.get(c))
        s += c;
    if (!c)
        return (std::cerr << "Empty File\n", 1);
    size_t pos = s.find(to_find);
    if (pos == std::string::npos)
        return (std::cout << "Nothing To Replace" << std::endl, 1);
    while (pos != std::string::npos)
    {
        if (to_find == to_repl)
            return (std::cout << "Nothing To Change" << std::endl, 1);
        s.erase(pos, to_find.length());
        s.insert(pos, to_repl);
        pos = s.find(to_find, pos + to_repl.length());
    }
    std::ofstream repl(f + ".replace");
    if (!repl.is_open())
        return (std::cerr << "File Error" << std::endl, 1);
    repl << s;
    repl.close();
    file.close();
    return (0);
}
