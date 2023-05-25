#include "Animal.hpp"

Animal::Animal()
{
	this->type = "Default ANIMAL";
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal parameterized constructor called\n";
}

Animal::Animal(const Animal &other)
{
	(*this) = other;
	std::cout << "Animal copy constructor called\n";
}

Animal&	Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Animal copy assignment operator called\n";
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

std::string	Animal::getType() const
{
	return (type);
}

void	Animal::makeSound() const
{
	std::cout << getType() << " says ! ! ! !\n";
}
