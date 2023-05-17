#include "Fixed.hpp"

Fixed::Fixed()
{
	fixedPointNum = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int intNum)
{
	setRawBits(intNum << numFractionalBits);
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float floatNum)
{
	setRawBits(roundf(floatNum * (1 << numFractionalBits)));
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	(*this) = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
	{
        this->setRawBits(other.getRawBits());
    }

	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const
{
	return (fixedPointNum);
}

void	Fixed::setRawBits(int const raw)
{
	fixedPointNum = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(fixedPointNum) / (1 << numFractionalBits));
}

int	Fixed::toInt(void) const
{
	return (getRawBits() >> numFractionalBits);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
