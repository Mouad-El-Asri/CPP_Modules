#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "Default constructor called for Contact object\n";
    m_NumContacts = 0;
    m_OldestIndex = 0;
}

PhoneBook::~PhoneBook()
{
    std::cout << "Destructor called for Contact object\n";
}
