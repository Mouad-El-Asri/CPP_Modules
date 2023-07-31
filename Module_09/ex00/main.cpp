#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::invalid_argument("Invalid number of arguments.");

		const char* inputFile = argv[1];
		std::ifstream input(inputFile);

		if (!input)
			throw std::runtime_error("Failed to open input file : " + std::string(inputFile) + ".");
		std::map<std::string, int> myMap;
		std::string line;
		bool fileIsEmpty = true;
		while (std::getline(input, line))
		{
			fileIsEmpty = false;
			std::istringstream lineParser(line);
			std::string key, value;

			if (std::getline(lineParser, key, '|') && std::getline(lineParser, value)) {
				myMap[key] = std::stoi(value);
			}
		}
		if (fileIsEmpty)
			throw std::runtime_error("The input file is empty.");
		input.close();
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error : " << e.what() << "\n";
        return (1);
	}
	return (0);
}
