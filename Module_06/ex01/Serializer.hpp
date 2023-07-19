#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <cstdint>

struct Data
{
	std::string	str;
	int			num;
};

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer &copy);
		Serializer			&operator=(const Serializer &copy);
		~Serializer();

		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif