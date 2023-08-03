#include "PmergeMe.hpp"

void	putNumbersInContainers(std::vector<int> &vectorNumbers, std::deque<int> &dequeNumbers, const std::string &input)
{
	if (input.find_first_not_of("0123456789") != std::string::npos)
		throw std::runtime_error("Input is invalid.");
	vectorNumbers.push_back(std::atoi(input.c_str()));
	dequeNumbers.push_back(std::atoi(input.c_str()));
}

void	merge(std::vector<int> &leftVec, \
		std::vector<int> &rightVec, std::vector<int> &vectorNumbers)
{
	std::size_t sizeLeft = leftVec.size();
	std::size_t sizeRight = rightVec.size();
	std::size_t i = 0, j = 0, k = 0;
	while (i < sizeLeft && j < sizeRight)
	{
		if (leftVec[i] <= rightVec[j])
			vectorNumbers[k++] = leftVec[i++];
		else
			vectorNumbers[k++] = rightVec[j++];
	}
	while (i < sizeLeft)
		vectorNumbers[k++] = leftVec[i++];
	while (j < sizeRight)
		vectorNumbers[k++] = rightVec[j++];
}

void	mergeSort(std::vector<int> &vectorNumbers)
{
	std::size_t size = vectorNumbers.size();
	if (size < 2)
		return ;
	std::size_t midSize = size / 2;
	std::vector<int> left(midSize);
	std::vector<int> right(size - midSize);
	for (std::size_t i = 0; i < midSize; i++)
		left[i] = vectorNumbers[i];
	for (std::size_t i = midSize; i < size; i++)
		right[i - midSize] = vectorNumbers[i];
	mergeSort(left);
	mergeSort(right);
	merge(left, right, vectorNumbers);
}

void	merge(std::deque<int> &leftVec, \
		std::deque<int> &rightVec, std::deque<int> &dequeNumbers)
{
	std::size_t sizeLeft = leftVec.size();
	std::size_t sizeRight = rightVec.size();
	std::size_t i = 0, j = 0, k = 0;
	while (i < sizeLeft && j < sizeRight)
	{
		if (leftVec[i] <= rightVec[j])
			dequeNumbers[k++] = leftVec[i++];
		else
			dequeNumbers[k++] = rightVec[j++];
	}
	while (i < sizeLeft)
		dequeNumbers[k++] = leftVec[i++];
	while (j < sizeRight)
		dequeNumbers[k++] = rightVec[j++];
}

void	mergeSort(std::deque<int> &dequeNumbers)
{
	std::size_t size = dequeNumbers.size();
	if (size < 2)
		return ;
	std::size_t midSize = size / 2;
	std::deque<int> left(midSize);
	std::deque<int> right(size - midSize);
	for (std::size_t i = 0; i < midSize; i++)
		left[i] = dequeNumbers[i];
	for (std::size_t i = midSize; i < size; i++)
		right[i - midSize] = dequeNumbers[i];
	mergeSort(left);
	mergeSort(right);
	merge(left, right, dequeNumbers);
}

void	printNumbers(std::vector<int> &vectorNumbers)
{
	for (std::size_t i = 0; i < vectorNumbers.size(); i++)
		std::cout << vectorNumbers[i] << " ";
	std::cout << std::endl;
}