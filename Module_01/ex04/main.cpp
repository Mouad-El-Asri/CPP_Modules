#include "StringReplace.hpp"

int main (int argc, char **argv)
{
    if (argc != 4)
	{
        std::cerr << "Error : number of arguments is not valid !\n";
        return (1);
    }
	StringReplace	replacer(argv[1]);
	replacer.strReplace(argv[2], argv[3]);

    return (0);
}
