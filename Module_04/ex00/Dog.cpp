#include "Dog.hpp"

Dog::Dog() : Animal("DOG")
{
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog &other)
{
	(*this) = other;
	std::cout << "Dog copy constructor called\n";
}

Dog&	Dog::operator=(const Dog &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Dog copy assignment operator called\n";
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

void	Dog::makeSound() const
{
	std::cout << this->getType() << " says Bow-wow\n";
}
