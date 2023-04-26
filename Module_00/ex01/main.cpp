#include "PhoneBook.hpp"

int	main()
{
	int	contactIndex = 0;
	PhoneBook	MyPhoneBook;
	std::string	input = "";

	while (input != "EXIT")
	{
		if (input == "ADD")
		{
			MyPhoneBook.addContact(contactIndex);
			contactIndex++;
		}
		else if (input == "SEARCH")
		{
			MyPhoneBook.printContacts();
			MyPhoneBook.searchForContact();
		}
		std::cout << "PhoneBook$ ";
		std::cin >> input;
	}

	return (0);
}
