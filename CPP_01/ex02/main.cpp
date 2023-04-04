#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "----------------ADDRESS-------------" << std::endl;
    std::cout << "stringPTR Address :   " << stringPTR << std::endl;
    std::cout << "stringREF Address :   " << &stringREF << std::endl;
    std::cout << "str Address       :   " << &str << std::endl;
    std::cout << "----------------VALUE---------------" << std::endl;
    std::cout << "stringPTR Value   : " << *stringPTR << std::endl;
    std::cout << "stringREF Value   : " << stringREF << std::endl;
    std::cout << "str Value         : " << str << std::endl;
}
