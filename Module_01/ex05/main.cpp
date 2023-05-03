#include "Harl.hpp"

int	main(void)
{
	Harl		Harl;
	std::string	input = "";

	std::cout << "Enter a level : ";
	std::cin >> input;
	harl.complain(input);

	return (0);
}
