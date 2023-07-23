#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *arr, int length, void (*func)(T))
{
	for (int i = 0; i < length; i++)
		func(arr[i]);
}

template <typename T>
void	printElem(T x)
{
	std::cout << x << "\n";
}

#endif