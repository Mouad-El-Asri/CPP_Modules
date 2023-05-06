#ifndef STRINGREPLAE_HPP
#define STRINGREPLAE_HPP

#include <iostream>
#include <string>
#include <fstream>

class StringReplace
{
	private:
		std::string	inputFile;
		std::string	outputFile;

	public:
		StringReplace(std::string filename);
		~StringReplace();

		void		strReplace(std::string str1, std::string str2);
		void		replaceStringInFile(std::string str1, std::string str2, \
					std::string inFileContent);
};

#endif
