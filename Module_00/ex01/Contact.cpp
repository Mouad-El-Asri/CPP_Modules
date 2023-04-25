#include "Contact.hpp"

Contact::Contact()
{
    std::cout << "Default constructor called for Contact object\n";
    m_FirstName = "";
    m_LastName = "";
    m_Nickname = "";
    m_PhoneNumber = "";
    m_DarkestSecret = "";
    m_Index = 0;
}

Contact::Contact(std::string FirstName, std::string LastName, \
                std::string Nickname, std::string PhoneNumber, \
                std::string DarkestSecret, int Index)
{
    std::cout << "Constructor called for Contact object\n";
    m_FirstName = FirstName;
    m_LastName = LastName;
    m_Nickname = Nickname;
    m_PhoneNumber = PhoneNumber;
    m_DarkestSecret = DarkestSecret;
    m_Index = Index;
}

Contact::~Contact()
{
    std::cout << "Destructor called for Contact object\n";
}
