#include "HumanB.hpp"

HumanB::HumanB()
{
	name = "Thorne";
	weapon = NULL;
	std::cout << "HumanB object called " << name << " created successfully !!!\n";
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
    std::cout << "HumanB object called " << this->name << " created successfully !!!\n";
}

HumanB::~HumanB()
{
	std::cout << "HumanB object called " << name << " destroyed successfully !!!\n";
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void    HumanB::attack(void) const
{
    if (weapon != NULL)
	{
        std::cout << name << " attacks with their " << weapon->getType() << '\n';
    }
	else
	{
        std::cout << name << " can't attack without a weapon. No weapon means no attack !!!\n";
    }
}
