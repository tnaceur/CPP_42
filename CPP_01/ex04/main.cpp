#include <iostream>
#include <fcntl.h>
#include <fstream>
#include <string>
#include <sstream>

int main(void)
{
    std::string f = "file";
    std::ifstream file(f);
    std::ofstream repl(f + ".replace");
    std::stringstream buffer;
    std::string s, a = "taha" , b = "naceur";
    buffer << file.rdbuf();
    s = buffer.str();
    size_t pos = s.find(a);
    while (pos != std::string::npos)
    {
        std::string before = s.substr(0, pos);
        std::string after = s.substr(pos + a.length());
        s = before + b + after;
        pos = s.find(a);
    }
    repl << s;
    repl.close();
    file.close();
    return (0);
}
