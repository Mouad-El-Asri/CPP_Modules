#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *myZombies;

	if (N)
	{
		myZombies = new Zombie[N];
		for (int i = 0; i < N; i++)
			myZombies[i].setZombieName(name);
	}
	else
		myZombies = NULL;
	return (myZombies);
}
