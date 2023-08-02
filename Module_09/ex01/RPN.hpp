#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

void	checkArgs(int argc, char **argv);
void	removeWhitespaces(std::string& str);
void	checkInputCharacters(std::string& input);
void	pushElementsToTheStacks(std::string& input, \
		std::stack<int>& numbersStack, std::stack<char>& operatorsStack);
// int		calculateResult(std::stack<int>& numbersStack, std::stack<char>& operatorsStack);

#endif