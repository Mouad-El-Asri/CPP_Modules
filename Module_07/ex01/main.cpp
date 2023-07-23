#include "iter.hpp"

int	main()
{
	int arr[] = {1, 2, 3, 4, 5};

	std::cout << "int array : \n";
	iter(arr, 5, printElem);
	return (0);
}
