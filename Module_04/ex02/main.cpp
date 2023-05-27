#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    const Animal* animals[2] = {new Dog(), new Cat()};
    for (int i = 0; i < 2; i++)
        delete animals[i];

    return (0);
}
