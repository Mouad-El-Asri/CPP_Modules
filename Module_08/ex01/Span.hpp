#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	vec;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		Span	&operator=(const Span &copy);
		~Span();

		void	addNumber(int num);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();
};

#endif