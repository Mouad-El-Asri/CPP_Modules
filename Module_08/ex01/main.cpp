#include "Span.hpp"

int main() {
    try
	{
        Span span(5);

        span.addNumber(1);
        span.addNumber(2);
        span.addNumber(3);

        std::vector<int> moreNumbers;
		moreNumbers.push_back(4);
		moreNumbers.push_back(7);
        span.addNumber(moreNumbers.begin(), moreNumbers.end());

		// for (std::vector<int>::iterator it = span.vec.begin(); it < span.vec.end(); it++)
    	// 	std::cout << ' ' << *it;
		// std::cout << '\n';

		std::vector<int> moooreNumbers;
		moooreNumbers.push_back(9);
		moooreNumbers.push_back(10);
        span.addNumber(moooreNumbers.begin(), moooreNumbers.end());
    }
	catch (const std::exception& e)
	{
        std::cerr << "Exception caught : " << e.what() << "\n";
    }

    return 0;
}