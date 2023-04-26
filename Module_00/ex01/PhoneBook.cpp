#include "PhoneBook.hpp"

void    PhoneBook::addContact(int contactIndex)
{
    m_contacts[contactIndex % 8].setup();
    m_contacts[contactIndex % 8].setIndex(contactIndex % 8);
}

void	PhoneBook::searchForContact() const
{
    int i;

    i = readIndexInput();
    m_contacts[i].printContactInfo(i);
}

void	PhoneBook::printContacts() const
{
    int i;

    i = -1;
    std::cout << "MY AWESOME PHONBOOK\n";
    while (++i < 8)
        m_contacts[i].viewContacts(i);
    //std::cout << std::endl;
}

int	PhoneBook::readIndexInput() const
{
    int     indexInput;
    bool    valid;

    indexInput = -1;
    valid = 0;
    while (!valid)
    {
        std::cout << "Enter the contact index : " << std::flush;
        std::cin >> indexInput;
        if (indexInput >= 0 && indexInput <= 8 && std::cin.good())
            valid = 1;
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Oops, that index is not valid. Please try again with a valid index.\n";
        }
    }
    return (indexInput);
}
