#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
    private:
        std::string m_FirstName;
        std::string m_LastName;
        std::string m_Nickname;
        std::string m_PhoneNumber;
        std::string m_DarkestSecret;
        int         m_Index;

    public:
        Contact();
        Contact(std::string FirstName, std::string LastName, \
                std::string Nickname, std::string PhoneNumber, \
                std::string DarkestSecret, int Index);
        ~Contact();
};

#endif