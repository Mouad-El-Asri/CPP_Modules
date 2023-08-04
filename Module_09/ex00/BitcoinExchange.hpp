#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <cstdlib>

std::ifstream				*checkArgs(int argc, char **argv);
std::map<int, float>		readAndStoreData();
float						stringToFloat(const std::string &value);
void						removeWhitespaces(std::string& str);
std::string					trimSpaces(const std::string& str);
bool						charIsNotInString(const std::string& str, char ch);
bool						isOnlyWhitespaces(const std::string& str);
int							countOccurrences(const std::string& str, char c);
void						readAndCheckFirstLine(std::ifstream &input);
int							checkDateErrors(const std::string& date);
int							checkDateFormat(int year, int month, int day);
float						checkValueErrors(const std::string& value);
void						readAndCheckInput(std::ifstream &input, std::map<int, float> dataMap);

#endif