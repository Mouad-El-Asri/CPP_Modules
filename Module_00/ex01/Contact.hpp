#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
    private:
        std::string m_first_name;
        std::string m_last_name;
        std::string m_nickname;
        std::string m_phone_number;
        std::string m_darkest_secret;
        int         index;

    public:
        Contact();
        ~Contact();
};

#endif