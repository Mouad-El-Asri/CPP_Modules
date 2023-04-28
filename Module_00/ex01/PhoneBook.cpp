#include "PhoneBook.hpp"

extern int	contactIndex;

void    PhoneBook::addContact(int contactIndex)
{
	std::cout << '\n';
    m_contacts[contactIndex % 8].setup();
    m_contacts[contactIndex % 8].setIndex(contactIndex % 8);
}

void	PhoneBook::searchForContact(void) const
{
    int i;

    i = readIndexInput();
    m_contacts[i].printContactInfo(i);
}

void	PhoneBook::printContacts(void) const
{
    int i;

    i = -1;
    std::cout << "\n###         MY AWESOME PHONEBOOK         ###\n";
	std::cout << "---------------------------------------------\n";
    while (++i < 8)
        m_contacts[i].listContacts(i);
    std::cout << '\n';
}

int	PhoneBook::stringIsNumber(std::string str) const
{
	bool isNumber;

	isNumber = 1;
    for (int i = 0; i < int(str.length()); i++)
	{
        if (!isdigit(str[i]))
		{
            isNumber = 0;
            break ;
        }
    }
	return (isNumber);
}

int	PhoneBook::readIndexInput(void) const
{
    std::string	indexInput;
    bool		flag;

    indexInput = -1;
    flag = 0;
    while (!flag)
    {
        std::cout << "- Enter the contact index : ";
        std::cin >> indexInput;
		if (!stringIsNumber(indexInput))
			std::cout << "Oops, that contact index is not a digit! Please try again.\n";
        else if (std::stoi(indexInput) >= 0 && std::stoi(indexInput) <= 8)
		{
			if (contactIndex == -1 || std::stoi(indexInput) > contactIndex)
				std::cout << "Oops, that contact index is still empty! Please try again.\n";
			else
				flag = 1;
		}
        else
			std::cout << "Oops, that index is not valid! Please try again with a valid index.\n";
    }
    return (std::stoi(indexInput));
}
