#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "Default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "Constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "Copy constructor called\n";
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	std::cout << "Copy assignment operator called\n";
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called\n";
}

void		ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " can't attack anymore. It has no energy points left.\n";
		return ;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!\n" ;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " can't take any more damage. It has no hit points left.\n";
		return ;
	}
	else if (this->hitPoints <= amount)
	{
		this->hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " has been destroyed!\n";
	}
	else
	{
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " hit points of damage.\n";
	}
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " can't be repaired. It has no energy points left.\n";
		return ;
	}
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " is being repaired and gains " << amount << " hit points back.\n";
}
