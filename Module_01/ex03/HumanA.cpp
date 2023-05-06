#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
	this->name = name;
	std::cout << "HumanA object called " << this->name << " created successfully !!!\n";
}

HumanA::~HumanA()
{
	std::cout << "HumanA object called " << this->name << " destroyed successfully !!!\n";
}

void    HumanA::attack(void) const
{
    std::cout << name << " attacks with their " << weapon.getType() << '\n';
}
