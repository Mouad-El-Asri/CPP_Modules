#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "Default WRONG ANIMAL";
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "WrongAnimal parameterized constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	(*this) = other;
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "WrongAnimal copy assignment operator called\n";
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}

std::string	WrongAnimal::getType() const
{
	return (type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << getType() << " says ! ! ! !\n";
}
