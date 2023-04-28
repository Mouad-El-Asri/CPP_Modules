#include "PhoneBook.hpp"

int	contactIndex = -1;

int	main(void)
{
	PhoneBook	MyPhoneBook;
	std::string	input;

	input = "";
	while (input != "EXIT")
	{
		if (input == "ADD")
		{
			contactIndex++;
			MyPhoneBook.addContact(contactIndex);
		}
		else if (input == "SEARCH")
		{
			MyPhoneBook.printContacts();
			MyPhoneBook.searchForContact();
		}
		std::cout << "PhoneBook$ ";
		std::cin >> input;
		if (std::cin.eof()) {
			return (0);
		}
	}

	return (0);
}
