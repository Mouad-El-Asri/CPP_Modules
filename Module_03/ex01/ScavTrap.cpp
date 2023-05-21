#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "< ScavTrap > - " << this->name << " default constructed." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;

    std::cout << "< ScavTrap > - " << this->name << " constructed.\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "< ScavTrap > - " << this->name << " destructed." << std::endl;
}

void    ScavTrap::attack(const std::string &target)
{
    if ( this->energyPoints <= 0 ) {
        std::cout << "< ScavTrap > - " << this->name << " is out of energy." << std::endl;
        return;
    }
    std::cout << "< ScavTrap > - " << this->name << " attacks " << target << " at range, causing " << this->attackDamage << " points of damage !" << std::endl;
    this->energyPoints -= 1;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gatekeeper mode!\n";
}