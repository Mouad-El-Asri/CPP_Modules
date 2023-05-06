#include "Zombie.hpp"

int	main(void)
{
	std::string zombieName_01 = "Hungry";
	std::string zombieName_02 = "Dead";
	std::string zombieName_03 = "Angry";

	Zombie firstZombie;
	firstZombie.announce();

	Zombie *secondZombie = newZombie(zombieName_02);
	secondZombie->announce();
	delete secondZombie;

	randomChump(zombieName_03);

	return (0);
}
