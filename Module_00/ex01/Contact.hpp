#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
    private:
        std::string m_firstName;
        std::string m_lastName;
        std::string m_nickname;
        std::string m_phoneNumber;
        std::string m_darkestSecret;
        int         m_index;

    public:
        Contact();
        void        setIndex(int index);
        bool        isEmpty() const;
        void        printContactInfo(int index) const;
        void        setup(void);
        std::string getInput(std::string str) const;
		std::string strLen(std::string str) const;
		void		viewContacts(int index) const;
};

#endif