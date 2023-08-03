#include "RPN.hpp"

int	main(int argc, char **argv)
{
	try
	{
		checkArgs(argc, argv);

		std::string			input(argv[1]);
		std::stack<int>		numbersStack;
		int					result;

		checkInputCharacters(input);
		pushElementsToTheStacks(input, numbersStack);
		result = numbersStack.top();
		std::cout << result << "\n";
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error : " << e.what() << "\n";
        return (1);
	}
	return (0);
}
