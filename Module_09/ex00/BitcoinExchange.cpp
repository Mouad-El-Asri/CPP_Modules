#include "BitcoinExchange.hpp"

void	checkArgs(int argc, char **argv)
{
	if (std::string(argv[0]) != "./btc")
		throw std::invalid_argument("Invalid program name.");
	if (argc != 2)
		throw std::invalid_argument("Invalid number of arguments.");

	const char* inputFile = argv[1];
	std::ifstream input(inputFile);

	if (!input)
		throw std::runtime_error("Failed to open input file : " + std::string(inputFile) + ".");
}

std::map<std::string, int>	readAndStoreData()
{
	std::string dataFile = "data.csv";
	std::ifstream data(dataFile);

	if (!data)
			throw std::runtime_error("Failed to open data file : " + dataFile + ".");

	std::map<std::string, int> dataMap;
	std::string line;
	std::getline(data, line);
	while (std::getline(data, line))
	{
		std::istringstream lineParser(line);
		std::string key, value;
		if (std::getline(lineParser, key, ',') && std::getline(lineParser, value))
			dataMap[key] = std::stoi(value);
	}
	data.close();
	return (dataMap);
}
