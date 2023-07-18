#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

struct Data
{
	std::string	s1;
	int			n;
};

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &copy);
		~Serializer();

		uintptr_t	serialize(Data *ptr);
		Data		*deserialize(uintptr_t raw);
};

#endif