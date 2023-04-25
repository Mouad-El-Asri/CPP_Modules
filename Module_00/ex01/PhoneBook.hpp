#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        int m_Contacts[8];
        int m_NumContacts;
        int m_OldestIndex;
    public:
        PhoneBook();
        ~PhoneBook();
};

#endif