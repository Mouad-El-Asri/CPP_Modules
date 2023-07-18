#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer default constructor called\n";
}

Serializer::Serializer(const Serializer &copy)
{
	*this = copy;
	std::cout << "Serializer copy constructor called\n";
}

Serializer &Serializer::operator=(const Serializer &copy)
{
	std::cout << "Serializer copy assignment operator called\n";
	if (this != &copy)
	{
	}
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called\n";
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
