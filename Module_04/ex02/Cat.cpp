#include "Cat.hpp"

Cat::Cat() : Animal("CAT")
{
	std::cout << "Cat default constructor called\n";
	brain = new Brain();
}

Cat::Cat(const Cat &other)
{
	this->brain = new Brain(*other.brain);
	std::cout << "Cat deep copy constructor called\n";
}

Cat&	Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		delete this->brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Cat deep copy assignment operator called\n";
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called\n";
}

void	Cat::makeSound() const
{
	std::cout << this->getType() << " says Meow\n";
}
