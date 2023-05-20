#include "Fixed.hpp"

Fixed::Fixed()
{
	fixedPointNum = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	this->setRawBits(other.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
        this->setRawBits(other.getRawBits());

	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (fixedPointNum);
}

void	Fixed::setRawBits(int const raw)
{
	fixedPointNum = raw;
}
