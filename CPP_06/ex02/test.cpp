#include <iostream>

class g{
public:
    void    print(){
        std::cout << "print" << std::endl;
    };
    ~g(){std::cout << "destructor called" << std::endl;};
};

int main()
{
    g a;
    a.~g();
    a.print();
}