#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	robot1("roboChamp");

	robot1.attack("roboWarrior");
	robot1.takeDamage(5);
	robot1.beRepaired(5);
	return (0);
}
