#include "easyfind.hpp"

int	main()
{
	std::vector<int>	vct;
	std::deque<int>		deq;

	for (int i = 0; i < 10; i++)
	{
		vct.push_back(i);
		deq.push_back(i);
	}

	std::cout << "Vector : ";
	for (std::vector<int>::iterator iter = vct.begin(); iter != vct.end(); iter++)
		std::cout << *iter << " ";
	std::cout << "\n";

	std::cout << "Deque : ";
	for (std::deque<int>::iterator iter = deq.begin(); iter != deq.end(); iter++)
		std::cout << *iter << " ";
	std::cout << "\n";

	std::cout << "\n";

	std::cout << "Vector : ";
	try
	{
		std::cout << *easyfind(vct, 3) << "\n";
		std::cout << *easyfind(vct, 11) << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << "Number not found\n";
	}
	
	std::cout << "\n";

	std::cout << "Deque : ";
	try
	{
		std::cout << *easyfind(deq, 1) << "\n";
		std::cout << *easyfind(deq, -1) << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << "Number not found\n";
	}

	return (0);
}
