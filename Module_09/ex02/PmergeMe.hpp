#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <ctime>

void	putNumbersInContainers(std::vector<int> &vectorNumbers, \
		std::deque<int> &dequeNumbers, const std::string &input);
void	merge(std::vector<int> &leftVec, \
		std::vector<int> &rightVec, std::vector<int> &vectorNumbers);
void	mergeSort(std::vector<int> &vectorNumbers);
void	merge(std::deque<int> &leftVec, \
		std::deque<int> &rightVec, std::deque<int> &dequeNumbers);
void	mergeSort(std::deque<int> &dequeNumbers);
void	printNumbers(std::vector<int> &vectorNumbers);

#endif