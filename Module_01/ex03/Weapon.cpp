#include "Weapon.hpp"

Weapon::Weapon()
{
	std::cout << "\n";
}

Weapon::Weapon(std::string type)
{
	setType(type);
}

Weapon::~Weapon()
{
	std::cout << "\n";
}

const	std::string&	Weapon::getType(void)
{
    return (type);
}

void	Weapon::setType(std::string type)
{
    this->type = type;
}

