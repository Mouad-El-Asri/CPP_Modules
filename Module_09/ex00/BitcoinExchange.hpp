#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <iterator>

void						checkArgs(int argc, char **argv);
std::map<std::string, int>	readAndStoreData();

#endif