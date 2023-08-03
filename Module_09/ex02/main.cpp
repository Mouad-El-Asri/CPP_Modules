#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (std::string(argv[0]) != "./PmergeMe")
			throw std::invalid_argument("Invalid program name.");
		std::vector<int>	vectorNumbers;
		std::deque<int>		dequeNumbers;
		for (int i = 1; i < argc; i++)
			putNumbersInContainers(vectorNumbers, dequeNumbers, std::string(argv[i]));
		double vecTimeToSort;
		double deqTimeToSort;
		clock_t start;
		clock_t end;
		std::cout << "Before :  ";
		printNumbers(vectorNumbers);
		start = clock();
		mergeSort(vectorNumbers);
		end = clock();
		vecTimeToSort = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		start = clock();
		mergeSort(dequeNumbers);
		end = clock();
		deqTimeToSort = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		std::cout << "After :  ";
		printNumbers(vectorNumbers);
		std::cout << "Time to process a range of " << vectorNumbers.size() \
		<< " elements with std::vector :  " << vecTimeToSort * 1000000 << " us" << "\n";
		std::cout << "Time to process a range of " << dequeNumbers.size() \
		<< " elements with std::deque :  " << deqTimeToSort * 1000000 << " us" << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << "\n";
		return (1);
	}
	
	return (0);
}
