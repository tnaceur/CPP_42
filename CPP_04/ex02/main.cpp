#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal animal[10];
    for (int i = 0; i < 5; i++)
        animal[i] = Dog();
    for (int i = 5; i < 10; i++)
        animal[i] = Cat();
    for (int i = 0; i < 10; i++)
        animal[i]->makeSound();
}

// int main()
// {
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     delete j;//should not create a leak
//     delete i;

//     system("leaks Polymorphism");
//     return 0;
// }