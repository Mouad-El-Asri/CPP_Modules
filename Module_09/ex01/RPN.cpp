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
	if (input.length() < 3)
		throw std::runtime_error("Input format is invalid.");
	std::string allowedCharacters = "0123456789+-/*";

	size_t found = input.find_first_not_of(allowedCharacters);
	if (found != std::string::npos)
		throw std::runtime_error("Disallowed character found in the input.");
}

void	pushElementsToTheStacks(std::string& input, std::stack<int>& numbersStack, std::stack<char>& operatorsStack)
{
	std::string strCharacter = input.substr(0, 2);
	std::string operators = "";
	if (strCharacter.find_first_not_of("0123456789") != std::string::npos)
		throw std::runtime_error("Input format is invalid.");
	else
	{
		numbersStack.push(strCharacter[0] - '0');
		numbersStack.push(strCharacter[1] - '0');
	}
	for (size_t i = 2; i < input.length(); i++)
	{
		strCharacter = input[i];
		if (strCharacter.find_first_not_of("+-*/") != std::string::npos)
			numbersStack.push(input[i] - '0');
		else
			operators += input[i];
	}
	for (int i = operators.length() - 1; i >= 0; i--)
		operatorsStack.push(operators[i]);
	if (numbersStack.size() != (operatorsStack.size() + 1))
		throw std::runtime_error("The size of numbers or operators is invalid.");
}

// int	calculateResult(std::stack<int>& numbersStack, std::stack<char>& operatorsStack)
// {
// 	int	result = numbersStack.top();
// 	size_t operatorsStackSize = operatorsStack.size();

// 	for (size_t i = 0; i < operatorsStackSize; i++)
// 	{
// 		std::cout << "result : " << result << "\n";
// 		numbersStack.pop();
// 		std::cout << "top : " << numbersStack.top() << "\n";
// 		if (operatorsStack.top() == '*')
// 			result = numbersStack.top() * result;
// 		else if (operatorsStack.top() == '/')
// 			result = numbersStack.top() / result;
// 		else if (operatorsStack.top() == '+')
// 			result = numbersStack.top() + result;
// 		else
// 			result = numbersStack.top() - result;
// 		operatorsStack.pop();
// 	}
// 	return (result);
// }
