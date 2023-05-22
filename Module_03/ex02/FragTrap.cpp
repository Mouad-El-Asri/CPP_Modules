#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;

    std::cout << "FragTrap parameterized constructor called\n";
}

FragTrap::FragTrap(const FragTrap& other)
{
	(*this) = other;
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	std::cout << "FragTrap copy assignment operator called\n";
	return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called\n";
}

void    FragTrap::highFivesGuys( void)
{
    std::cout << "FragTrap " << this->name << " high fives everybody.\n";
}