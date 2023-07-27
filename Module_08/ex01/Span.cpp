#include "Span.hpp"

Span::Span()
{
	N = 0;
	std::cout << "Span default constructor called\n";
}

Span::Span(unsigned int N)
{
	this->N = N;
	std::cout << "Span constructor called\n";
}

Span::Span(const Span &other)
{
	std::cout << "Span copy constructor called\n";
	(*this) = other;
}

Span	&Span::operator=(const Span &other)
{
	std::cout << "Span assingment operator called\n";
	if (this != &other)
	{
		N = other.N;
		vec = other.vec;
	}
	return (*this);
}

Span::~Span()
{
	std::cout << "Span destructor called\n";
}

void	Span::addNumber(int num)
{
	if (vec.size() == N)
		throw std::exception();
	vec.push_back(num);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (vec.size() + std::distance(begin, end) > N)
		throw std::exception();
	vec.insert(vec.end(), begin, end);
}

int		Span::shortestSpan()
{
	if (vec.size() <= 1)
		throw std::exception();

	std::vector<int> tmp(vec);
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (std::vector<int>::iterator iter = tmp.begin(); iter < tmp.end() - 1; iter++)
	{
		if (*(iter + 1) - *iter < min)
			min = *(iter + 1) - *iter;
	}
	return (min);
}

int		Span::longestSpan()
{
	if (vec.size() <= 1)
		throw std::exception();

	std::vector<int> tmp(vec);
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}
