#include "Dog.hpp"

Dog::Dog() : Animal("DOG")
{
	std::cout << "Dog default constructor called\n";
	brain = new Brain();
}

Dog::Dog(const Dog &other)
{
	this->brain = new Brain(*other.brain);
	std::cout << "Dog deep copy constructor called\n";
}

Dog&	Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		delete this->brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Dog deep copy assignment operator called\n";
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called\n";
}

void	Dog::makeSound() const
{
	std::cout << this->getType() << " says Bow-wow\n";
}
