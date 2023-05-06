#include "Weapon.hpp"

Weapon::Weapon()
{
	setType("Basic Sword");
	std::cout << "Weapon object of type " << type << " created successfully !!!\n";
}

Weapon::Weapon(std::string type)
{
	setType(type);
	std::cout << "Weapon object of type " << type << " created successfully !!!\n";
}

Weapon::~Weapon()
{
	std::cout << "Weapon object of type " << type << " destroyed successfully !!!\n";
}

const	std::string&	Weapon::getType(void) const
{
    return (type);
}

void	Weapon::setType(std::string type)
{
    this->type = type;
}
