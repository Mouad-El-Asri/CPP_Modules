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
	if (input.length() < 3 || strchr("0123456789", input[input.length() - 1]))
		throw std::runtime_error("Input format is invalid.");
	std::string allowedCharacters = "0123456789+-/*";

	size_t found = input.find_first_not_of(allowedCharacters);
	if (found != std::string::npos)
		throw std::runtime_error("Disallowed character found in the input.");
}

void	pushElementsToTheStacks(std::string& input, std::stack<int>& numbersStack)
{
	std::string strCharacter = input.substr(0, 2);
	std::string operators = "";
	if (strCharacter.find_first_not_of("0123456789") != std::string::npos)
		throw std::runtime_error("Input format is invalid.");
	for (size_t i = 0; i < input.length(); i++)
	{
		strCharacter = input[i];
		if (strCharacter.find_first_not_of("+-*/") == std::string::npos)
			operators += input[i];
	}

	int	result = 0;
	int	indx = 0;

	if (input.length() != ((operators.length() * 2) + 1))
		throw std::runtime_error("The size of numbers or operators is invalid.");
	for (size_t i = 0; i < input.length(); i++)
	{
		strCharacter = input[i];
		if (strCharacter.find_first_not_of("+-*/") != std::string::npos)
			numbersStack.push(input[i] - '0');
		else
			calculateResult(numbersStack, operators, result, indx);
	}
}

void	calculateResult(std::stack<int>& numbersStack, const std::string &operators, \
		int &result, int &indx)
{
	result = numbersStack.top();
	numbersStack.pop();
	if (operators[indx] == '+')
		result = numbersStack.top() + result;
	else if (operators[indx] == '-')
		result = numbersStack.top() - result;
	else if (operators[indx] == '*')
		result = numbersStack.top() * result;
	else
	{
		if (result == 0)
			throw std::runtime_error("Divide by zero error");
		result = numbersStack.top() / result;
	}
	numbersStack.pop();
	numbersStack.push(result);
	indx++;
}
