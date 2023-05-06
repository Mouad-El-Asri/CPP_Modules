#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie *myZombie;

	myZombie = new Zombie(name);
	return (myZombie);
}
