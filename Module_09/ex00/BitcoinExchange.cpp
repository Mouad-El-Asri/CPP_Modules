#include "BitcoinExchange.hpp"

std::ifstream	*checkArgs(int argc, char **argv)
{
	if (std::string(argv[0]) != "./btc")
		throw std::invalid_argument("Invalid program name.");
	if (argc != 2)
		throw std::invalid_argument("Invalid number of arguments.");

	const char* inputFile = argv[1];
	std::ifstream *input = new std::ifstream(inputFile);

	if (!input)
		throw std::runtime_error("Failed to open input file : " + std::string(inputFile) + ".");
	return (input);
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

void	removeWhitespaces(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
}

bool	charIsNotInString(const std::string& str, const char ch)
{
    return (str.find(ch) == std::string::npos);
}

bool	isOnlyWhitespaces(const std::string& str)
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
	{
        if (!std::isspace(*it))
            return (0);
    }
    return (1);
}

int	countOccurrences(const std::string& str, char c) {
    int count = 0;
    for (std::string::size_type i = 0; i < str.length(); ++i)
	{
        if (str[i] == c)
            count++;
    }
    return (count);
}

void	readAndCheckFirstLine(std::ifstream &input)
{
	std::string line;
	bool fileIsEmpty = true;
	while (std::getline(input, line))
	{
		if (line.empty())
			continue ;
		removeWhitespaces(line);
		std::stringstream lineParser(line);
		std::string key, value;
		if (std::getline(lineParser, key, '|') && std::getline(lineParser, value))
		{
			if (key != "date" || value != "value")
				throw std::runtime_error("Invalid format in the first line of input file.");
			fileIsEmpty = false;
			break ;
		}
	}
	if (fileIsEmpty)
		throw std::runtime_error("The input file is empty.");
}

int	checkDateErrors(const std::string& date)
{
	if (date.empty())
	{
		std::cerr << "Error: empty date.\n";
		return (1);
	}
	if (date.size() != 10 || countOccurrences(date, '-') != 2)
	{
		std::cerr << "Error: invalid date format.\n";
		return (1);
	}
	std::stringstream dateParser(date);
	std::string year, month, day;
	if (std::getline(dateParser, year, '-') && std::getline(dateParser, month, '-') && std::getline(dateParser, day))
	{
		if (year.size() != 4 || month.size() != 2 || day.size() != 2)
		{
			std::cerr << "Error: invalid date format.\n";
			return (1);
		}
	}
	else
	{
		std::cerr << "Error: invalid date format.\n";
		return (1);
	}
	std::stringstream yearParser(year);
	std::stringstream monthParser(month);
	std::stringstream dayParser(day);
	int	intYear, intMonth, intDay;
	if (!(yearParser >> intYear) || !(monthParser >> intMonth) || !(dayParser >> intDay))
	{
		std::cerr << "Error: date contains bad characters => " << date << "\n";
		return (1);
	}
	return (checkDateFormat(intYear, intMonth, intDay));
}

int	checkDateFormat(int year, int month, int day)
{
	if (year < 2009 || year > 2022)
	{
		std::cerr << "Error: invalid year.\n";
		return (1);
	}
	if (month < 1 || month > 12)
	{
		std::cerr << "Error: invalid month.\n";
		return (1);
	}
	bool	is29Days = month == 2;
	bool	is30Days = (month == 4 || month == 6 || month == 9 || month == 11);
    bool	is31Days = (month == 1 || month == 3 || month == 5 || month == 7 ||
					month == 8 || month == 10 || month == 12);
	if (day < 1 || day > 31 || \
		((is29Days && day > 29) || \
		(is30Days && day > 30) || (is31Days && day > 31)))
	{
		std::cerr << "Error: invalid day.\n";
		return (1);
	}
	return (0);
}

void	readAndCheckInput(std::ifstream &input)
{
	std::string line;

	readAndCheckFirstLine(input);
	while (std::getline(input, line))
	{
		if (line.empty() || isOnlyWhitespaces(line))
			continue ;
		if (charIsNotInString(line, '|'))
		{
			std::cerr << "Error: bad input => " << line << "\n";
			continue ;
		}
		removeWhitespaces(line);
		std::stringstream lineParser(line);
		std::string key, value;
		std::getline(lineParser, key, '|') && std::getline(lineParser, value);
		if (checkDateErrors(key))
			continue ;
		if (value.empty())
		{
			std::cerr << "Error: empty value.\n";
			continue ;
		}
		std::stringstream valueParser(value);
		int num;
		if (!(valueParser >> num))
		{
			std::cerr << "Error: bad value => " << value << "\n";
			continue ;
		}
		if (num < 0)
		{
			std::cerr << "Error: not a positive number.\n";
			continue ;
		}
		if(num > 1000)
		{
			std::cerr << "Error: too large number.\n";
			continue ;
		}
		if (countOccurrences(value, '.') > 1 || countOccurrences(value, '+'))
		{
			std::cerr << "Error: invalid value format.\n";
			continue ;
		}
	}
	input.close();
}
