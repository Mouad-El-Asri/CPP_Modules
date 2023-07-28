#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack	&operator=(const MutantStack &other);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin();
		iterator	end();
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << "MutantStack default constructor called\n";
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other)
{
	std::cout << "MutantStack copy constructor called\n";
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
	std::cout << "MutantStack assignement operator called\n";
	if (this != &other)
	{
		MutantStack<T> tmp(other);
        std::swap(*this, tmp);
	}
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack destructor called\n";
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

#endif