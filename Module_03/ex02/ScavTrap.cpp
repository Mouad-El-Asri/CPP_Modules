#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;

    std::cout << "ScavTrap parameterized constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	(*this) = other;
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	std::cout << "ScavTrap copy assignment operator called\n";
	return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called\n";
}

void    ScavTrap::attack(const std::string &target)
{
    if (this->energyPoints == 0)
	{
        std::cout << "ScavTrap " << name << " can't attack anymore. It has no energy points left.\n";
        return ;
    }
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!\n" ;
    this->energyPoints -= 1;
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!\n";
}
