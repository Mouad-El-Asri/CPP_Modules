#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
    private:
        std::string m_firstName;
        std::string m_lastName;
        std::string m_nickname;
        std::string m_phoneNumber;
        std::string m_darkestSecret;
        int         m_index;

		void		phoneNumber(void);
		bool        isEmpty(void) const;
		std::string getInput(std::string str) const;
		std::string strLen(std::string str) const;

    public:
        Contact();
        void        setIndex(int index);
        void        printContactInfo(int index) const;
        void        setup(void);
		void		listContacts(int index) const;
};

#endif
