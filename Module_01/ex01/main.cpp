#include "Zombie.hpp"

int	main(void)
{
	int			N;
	std::string name;
	Zombie		*myZombies;

	name = "walker";
	N = 0;
	myZombies = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
		myZombies[i].announce();
	delete [] myZombies;

	return (0);
}
