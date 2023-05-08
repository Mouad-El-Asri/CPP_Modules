#include "StringReplace.hpp"

StringReplace::StringReplace(std::string filename)
{
	inputFile = filename;
	outputFile = inputFile + ".replace";
	std::cout << "Object created successfully !!!\n";
}

StringReplace::~StringReplace()
{
	std::cout << "Object destroyed successfully !!!\n";
}

void	StringReplace::replaceStringInFile(std::string str1, std::string str2, \
		std::string inFileContent)
{
	std::ofstream	outFile(outputFile);
	int				startPosition = 0;
	size_t			position = inFileContent.find(str1, startPosition);
	while (position != std::string::npos)
	{
		inFileContent.erase(position, str1.length());
		inFileContent.insert(position, str2);
		startPosition = position + str2.length();
		position = inFileContent.find(str1, startPosition);
	}
	outFile << inFileContent;
	outFile.close();
}

void	StringReplace::strReplace(std::string str1, std::string str2)
{
	std::ifstream	inFile(inputFile);
	std::string		inFileContent = "";

	if (!inFile.is_open())
	{
		std::cerr << "ERROR : the file couldn't be opened.\n";
		exit(1);
	}
	if (!std::getline(inFile, inFileContent, '\0'))
	{
		std::cerr << "ERROR : unable to read from file.\n";
		exit(1);
	}
	replaceStringInFile(str1, str2, inFileContent);
	inFile.close();
}
