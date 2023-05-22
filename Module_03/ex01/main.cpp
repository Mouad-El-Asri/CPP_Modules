#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	robot1("roboChamp");

	robot1.attack("roboWarrior");
	robot1.takeDamage(10);
	robot1.beRepaired(10);
	return (0);
}