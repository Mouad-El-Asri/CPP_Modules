#include "Contact.hpp"

Contact::Contact() {
    std::cout << "Default constructor called for Contact object\n";
    m_first_name = "";
    m_last_name = "";
    m_nickname = "";
    m_phone_number = "";
    m_darkest_secret = "";
    index = 0;
}

Contact::~Contact()
{
    std::cout << "Destructor called for Contact object\n";
}
