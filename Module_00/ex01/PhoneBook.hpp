#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cctype>

class PhoneBook
{
    private:
        Contact	m_contacts[8];

		int		stringIsNumber(std::string str) const;
        int     readIndexInput() const;

    public:
		void    addContact(int contactIndex);
        void    searchForContact() const;
        void    printContacts() const;
};

#endif
