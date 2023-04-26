#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact 	m_contacts[8];

    public:
		void    addContact(int contactIndex);
        void    searchForContact() const;
        void    printContacts() const;
        int     readIndexInput() const;
};

#endif