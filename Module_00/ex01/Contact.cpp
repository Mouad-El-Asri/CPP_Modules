#include "Contact.hpp"

Contact::Contact()
{
    m_firstName = "";
    m_lastName = "";
    m_nickname = "";
    m_phoneNumber = "";
    m_darkestSecret = "";
    m_index = 0;
}

void	Contact::setIndex(int index)
{
    m_index = index;
}

bool	Contact::isEmpty() const
{
    return ((m_firstName.empty()) || (m_lastName.empty()) || \
            (m_nickname.empty()) || m_phoneNumber.empty() || \
			m_darkestSecret.empty());
}

void	Contact::printContactInfo(int index) const
{
    if (isEmpty())
        return ;
	std::cout << '\n';
    std::cout << "# Contact Index : " << index << '\n';
    std::cout << "# First Name : " << m_firstName << '\n';
    std::cout << "# Last Name : " << m_lastName << '\n';
    std::cout << "# Nickname : " << m_nickname << '\n';
    std::cout << "# Phone Number : " << m_phoneNumber << '\n';
    std::cout << "# Darkest Secret : " << m_darkestSecret << '\n';
	std::cout << '\n';
}

void	Contact::phoneNumber()
{
	bool isNumber;

	isNumber = 1;
	m_phoneNumber = getInput("- Enter your phone number : ");
	while (isNumber)
	{
		for (int i = 0; i < int(m_phoneNumber.length()); i++)
		{
			if (!isdigit(m_phoneNumber[i]))
			{
				isNumber = 0;
				std::cout << "Oops, that is not a correct phone number!"
							" Please try again with a valid phone number.\n";
				break ;
			}
		}
		if (isNumber)
			break ;
		isNumber = 1;
		m_phoneNumber = getInput("- Enter your phone number : ");
	}
}

void	Contact::setup(void)
{
	std::cin.ignore();
    m_firstName = getInput("- Enter you first name : ");
    m_lastName = getInput("- Enter your last name : ");
    m_nickname = getInput("- Enter your nickname : ");
	phoneNumber();
    m_darkestSecret = getInput("- Enter your darkest secret : ");
	std::cout << '\n';
}

std::string	Contact::getInput(std::string str) const
{
    std::string input;
    bool flag;

	input = "";
	flag = 0;
    while (!flag)
    {
        std::cout << str;
        std::getline(std::cin, input);
		if (input.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
			std::cout << "Oops, the input contains only whitespaces! Please try again.\n";
        else if (!input.empty())
            flag = 1;
        else
            std::cout << "Oops, that input is not valid! Please try again with a valid input.\n";
    }
    return (input);
}

void	Contact::listContacts(int index) const
{
    if (isEmpty())
        return ;
    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << strLen(m_firstName);
    std::cout << "|" << std::setw(10) << strLen(m_lastName);
    std::cout << "|" << std::setw(10) << strLen(m_nickname);
    std::cout << "|\n";
}

std::string Contact::strLen(std::string str) const
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}
