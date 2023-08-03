#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

void	checkArgs(int argc, char **argv);
void	removeWhitespaces(std::string& str);
void	checkInputCharacters(std::string& input);
void	pushElementsToTheStacks(std::string& input, std::stack<int>& numbersStack);
void	calculateResult(std::stack<int>& numbersStack, const std::string &operators, \
		int &result, int &indx);

#endif