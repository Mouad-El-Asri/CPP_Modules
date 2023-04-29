#include "Zombie.hpp"

Zombie::Zombie()
{
	name = "";
	std::cout << "New Zombie is coming to life ... BRAINzzzZ!!\n";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "New Zombie called " << name << " is coming to life ... BEWARE!!";
}	

Zombie::~Zombie()
{
	std::cout << "Sending the Zombie " << name << " back to the grave ... ENJOY!!";
}

void	announce(void)
{

}
