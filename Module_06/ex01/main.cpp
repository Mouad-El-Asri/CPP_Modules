#include "Serializer.hpp"

int	main(void)
{
	Data		*data = new Data;

	data->str = "Hello Mouad, how old are you ?";
	data->num = 21;

	uintptr_t	serialized = Serializer::serialize(data);
	std::cout << "Serialized data: " << serialized << "\n";
	std::cout << "Serialized data: " << data << "\n";

	Data		*deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized data:\n";
	std::cout << "str: " << deserialized->str << "\n";
	std::cout << "num: " << deserialized->num << "\n";

	delete data;

	return (0);
}
