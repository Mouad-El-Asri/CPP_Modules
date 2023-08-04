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

std::map<int, float>	readAndStoreData()
{
	std::string dataFile = "data.csv";
	std::ifstream data(dataFile);

	if (!data)
			throw std::runtime_error("Failed to open data file : " + dataFile + ".");

	std::map<int, float> dataMap;
	std::string line;
	std::getline(data, line);
	while (std::getline(data, line))
	{
		std::istringstream lineParser(line);
		std::string key, value;
		std::string newKey;
		if (std::getline(lineParser, key, ',') && std::getline(lineParser, value))
		{
			for (unsigned long i = 0; i < key.length(); i++)
			{
				if (key[i] != '-')
					newKey += key[i];
			}
			dataMap[std::atoi(newKey.c_str())] = stringToFloat(value);
		}
	}
	data.close();
	return (dataMap);
}

float	stringToFloat(const std::string &value)
{
	float result;
	std::stringstream valueParser(value);
	if (!(valueParser >> result))
		throw std::runtime_error("Invalid float conversion: " + value);
	return (result);
}

void	removeWhitespaces(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
}

std::string	trimSpaces(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t\r\n");
    size_t end = str.find_last_not_of(" \t\r\n");

    return (str.substr(start, end - start + 1));
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
	if (year < 2009)
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

float	checkValueErrors(const std::string& value)
{
	if (value.empty())
	{
		std::cerr << "Error: empty value.\n";
		return (-1);
	}
	if (value[0] == '.' || value[value.length() - 1] == '.' || \
		value.find_first_not_of("-+0123456789.") != std::string::npos)
	{
		std::cerr << "Error: bad value => " << value << "\n";
		return (-1);
	}
	std::stringstream valueParser(value);
	float num;
	if (!(valueParser >> num))
	{
		std::cerr << "Error: bad value => " << value << "\n";
		return (-1);
	}
	else if (countOccurrences(value, '.') > 1 || countOccurrences(value, '+'))
	{
		std::cerr << "Error: invalid value format.\n";
		return (-1);
	}
	else if (num < 0)
	{
		std::cerr << "Error: not a positive number.\n";
		return (-1);
	}
	else if(num > 1000)
	{
		std::cerr << "Error: too large number.\n";
		return (-1);
	}
	return (num);
}

void	readAndCheckInput(std::ifstream &input, std::map<int, float> dataMap)
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
		std::stringstream lineParser(line);
		std::string key, value;
		std::getline(lineParser, key, '|') && std::getline(lineParser, value);
		removeWhitespaces(key);
		value = trimSpaces(value);
		if (checkDateErrors(key) || checkValueErrors(value) == -1)
			continue ;
		float num = checkValueErrors(value);
		std::string newKey;
		for (unsigned long i = 0; i < key.length(); i++)
		{
			if (key[i] != '-')
				newKey += key[i];
		}
		std::map<int, float>::iterator it = dataMap.lower_bound(std::atoi((newKey.c_str())));
		if (it == dataMap.begin())
		{
			std::cerr << "Error: date is too early => " << key << "\n";
			continue ;
		}
		else if (it == dataMap.end() || it->first != std::atoi(newKey.c_str()))
			it--;
		std::cout << key << " => " << num << " = " << num * it->second << "\n";
	}
	input.close();
}
