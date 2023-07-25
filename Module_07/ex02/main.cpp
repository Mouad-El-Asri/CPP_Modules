#include "Array.hpp"

int main(void)
{
	Array<int> intArr(5);

	std::cout << "intArr size: " << intArr.size() << "\n";

	for (unsigned int i = 0; i < intArr.size(); i++)
		intArr[i] = i + 1;

	std::cout << "intArr : \n";
	for (unsigned int i = 0; i < intArr.size(); i++)
		std::cout << intArr[i] << "\n";

	try
	{
		std::cout << "intArr[" << intArr[4] - 1 << "] : " << intArr[4] << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	return (0);
}
