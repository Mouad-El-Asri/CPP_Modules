#include "easyfind.hpp"

int	main()
{
	std::vector<int>	vct;
	std::list<int>		lst;
	std::deque<int>		deq;

	for (int i = 0; i < 10; i++)
	{
		vct.push_back(i);
		lst.push_back(i);
		deq.push_back(i);
	}

	std::cout << "Vector : ";
	for (std::vector<int>::iterator iter = vct.begin(); iter != vct.end(); iter++)
		std::cout << *iter << " ";
	std::cout << "\n";

	std::cout << "List : ";
	for (std::list<int>::iterator iter = lst.begin(); iter != lst.end(); iter++)
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
		std::cout << *easyfind(vct, 3) << std::endl;
		std::cout << *easyfind(vct, 11) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Number not found\n";
	}
	
	std::cout << "\n";

	std::cout << "List : ";
	try
	{
		std::cout << *easyfind(lst, 7) << std::endl;
		std::cout << *easyfind(lst, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Number not found\n";
	}

	std::cout << "\n";

	std::cout << "Deque : ";
	try
	{
		std::cout << *easyfind(deq, 1) << std::endl;
		std::cout << *easyfind(deq, -1) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Number not found\n";
	}

	return (0);
}
