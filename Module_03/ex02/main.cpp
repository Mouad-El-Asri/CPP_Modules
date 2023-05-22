#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	robot1("roboChamp");

	robot1.attack("roboWarrior");
	robot1.takeDamage(10);
	robot1.beRepaired(10);
	robot1.highFivesGuys();
	return (0);
}
