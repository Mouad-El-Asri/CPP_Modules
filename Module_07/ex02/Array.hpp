#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array
{
	private:
		T				*arr;
		unsigned int	arrSize;

	public:
		Array();
		Array(unsigned int n);
		Array(Array const &other);
		Array			&operator=(Array const &other);
		~Array();

		T				&operator[](unsigned int index);

		unsigned int size() const;

		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

template <typename T>
Array<T>::Array()
{
	arrSize = 0;
	arr = new T[0];
	std::cout << "Default constructor called\n";
}


template <typename T>
Array<T>::Array(unsigned int n)
{
	arrSize = n;
	arr = new T[n];
	std::cout << "Parametrized constructor called\n";
}

template <typename T>
Array<T>::Array(Array const &other)
{
	std::cout << "Copy constructor called\n";
	(*this) = other;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
	std::cout << "Assignement operator called\n";
	if (this != &other)
	{
		if (arr)
			delete[] arr;
		arrSize = other.arrSize;
		arr = new T[arrSize];
		for (unsigned int i = 0; i < arrSize; i++)
			arr[i] = other.arr[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	if (arr)
		delete[] arr;
	std::cout << "Destructor called\n";
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= arrSize)
		throw OutOfRangeException();
	return arr[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (arrSize);
}

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw()
{
	return "Index Out Of Range\n";
}

#endif