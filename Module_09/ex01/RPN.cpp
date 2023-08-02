#include "RPN.hpp"

void	checkArgs(int argc, char **argv)
{
	if (std::string(argv[0]) != "./RPN")
		throw std::invalid_argument("Invalid program name.");
	if (argc != 2)
		throw std::invalid_argument("Invalid number of arguments.");
}

void	removeWhitespaces(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
}

void	checkInputCharacters(std::string& input)
{
	removeWhitespaces(input);
	std::string disallowedCharacters = "0123456789+-/*";

	size_t found = input.find_first_not_of(disallowedCharacters);
	if (found != std::string::npos)
		throw std::runtime_error("Disallowed character found in the input.");
}

void	pushElementsToTheStacks(std::string& input, std::stack<int>& numbersStack, std::stack<char>& operatorsStack)
{
	std::string strCharacter;

	for (size_t i = 0; i < input.length(); i++)
	{
		strCharacter = input[i];
		if (strCharacter.find_first_not_of("+-*/") != std::string::npos)
			numbersStack.push(input[i]);
		else
			operatorsStack.push(input[i]);
	}
	if (numbersStack.size() != (operatorsStack.size() + 1))
		throw std::runtime_error("The size of numbers or operators is invalid.");
}
