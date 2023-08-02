#include "RPN.hpp"

int	main(int argc, char **argv)
{
	try
	{
		checkArgs(argc, argv);

		std::string			input(argv[1]);
		std::stack<int>		numbersStack;
		std::stack<char>	operatorsStack;
		// int					result;

		checkInputCharacters(input);
		pushElementsToTheStacks(input, numbersStack, operatorsStack);

		// result = calculateResult(numbersStack, operatorsStack);
		// std::cout << result << "\n";
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error : " << e.what() << "\n";
        return (1);
	}
	return (0);
}
