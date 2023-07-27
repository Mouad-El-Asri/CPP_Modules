#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <deque>

template <typename T>
typename T::iterator easyfind(T &container, int num)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), num);
	if (iter == container.end())
		throw std::exception();
	return (iter);
}

#endif