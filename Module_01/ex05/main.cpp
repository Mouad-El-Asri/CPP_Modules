#include "Harl.hpp"

int	main()
{
	Harl		newHarl;
	std::string	input = "";

	std::cout << "Please enter the desired level : ";
	std::cin >> input;
	newHarl.complain(input);

	return (0);
}
