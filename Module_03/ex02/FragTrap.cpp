#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap " << name << " constructor" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " is ready for some fragging action!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " is out of the game!" << std::endl;
}

void    FragTrap::highFivesGuys( void ) {
    if (this->energyPoints <= 0 ) {
        std::cout << "| FragTrap | - " << this->name << " is out of energy." << std::endl;
        return;
    }
    std::cout << "| FragTrap | - " << this->name << " high fives everybody." << std::endl;
    this->energyPoints -= 1;
}