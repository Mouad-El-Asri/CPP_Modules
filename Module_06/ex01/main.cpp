#include "Serializer.hpp"

int	main(void)
{
	Serializer	serializer;
	Data		data;
	uintptr_t	raw;

	data.s1 = "Hello, world!";
	data.n = 42;
	raw = serializer.serialize(&data);
	std::cout << "Serialized data : " << raw << "\n";
	std::cout << "Deserialized data : " << serializer.deserialize(raw) << "\n";

	return (0);
}
