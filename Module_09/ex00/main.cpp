#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	try
	{
		readAndCheckInput(*checkArgs(argc, argv));
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error : " << e.what() << "\n";
        return (1);
	}
	return (0);
}
