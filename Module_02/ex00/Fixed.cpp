#include "Fixed.hpp"

Fixed::Fixed()
{
	fixedPointNum = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int fixedPointNum)
{
	this->fixedPointNum = fixedPointNum;
	std::cout << "Constructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
}

Fixed& operator=(const Fixed& other)
{
	if (this != &other) {
        fixedPointNum = other.fixedPointNum;
    }
	std::cout << "Copy assignment operator called\n";

	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const
{

}

void	Fixed::setRawBits(int const raw)
{

}
