#include "Contact.hpp"
#include <iomanip>

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
    return ((m_firstName.empty()) || (m_lastName.empty()) ||
            (m_nickname.empty()));
}

void	Contact::printContactInfo(int index) const
{
    if (isEmpty())
        return ;
    std::cout << "Contact Index : " << index << '\n';
    std::cout << "First Name : " << m_firstName << '\n';
    std::cout << "Last Name : " << m_lastName << '\n';
    std::cout << "Nickname : " << m_nickname << '\n';
}

void	Contact::setup(void)
{
    m_firstName = getInput("Enter you first name : ");
    m_lastName = getInput("Enter your last name : ");
    m_nickname = getInput("Enter your nickname : ");
    m_phoneNumber = getInput("Enter your phone number : ");
    m_darkestSecret = getInput("Enter your darkest secret : ");
}

std::string	Contact::getInput(std::string str) const
{
    std::string input = "";
    bool valid = 0;

    while (!valid)
    {
        std::cout << str << '\n';
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty())
            valid = 1;
        else
        {
            std::cin.clear();
            std::cout << "Oops, that input is not valid. Please try again with a valid input.\n";
        }
    }
    return (input);
}

void	Contact::viewContacts(int index) const
{
    if (isEmpty())
        return ;
    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << strLen(m_firstName);
    std::cout << "|" << std::setw(10) << strLen(m_lastName);
    std::cout << "|" << std::setw(10) << strLen(m_nickname);
    //std::cout << "|" << std::endl;
}

std::string Contact::strLen(std::string str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return (str);
}

// check good