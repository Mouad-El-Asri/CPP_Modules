#include "Fixed.hpp"

Fixed::Fixed()
{
	fixedPointNum = 0;
}

Fixed::Fixed(const int intNum)
{
	setRawBits(intNum << numFractionalBits);
}

Fixed::Fixed(const float floatNum) 
{
	setRawBits(roundf(floatNum * (1 << numFractionalBits)));
}

Fixed::Fixed(const Fixed &other)
{
	(*this) = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
        this->setRawBits(other.getRawBits());
    }

	return (*this);
}

Fixed::~Fixed()
{
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

bool	Fixed::operator>(const Fixed& other) const
{
    return (fixedPointNum > other.fixedPointNum);
}

bool	Fixed::operator<(const Fixed& other) const
{
    return (fixedPointNum < other.fixedPointNum);
}

bool	Fixed::operator>=(const Fixed& other) const
{
    return (fixedPointNum >= other.fixedPointNum);
}

bool	Fixed::operator<=(const Fixed& other) const
{
    return (fixedPointNum <= other.fixedPointNum);
}

bool	Fixed::operator==(const Fixed& other) const
{
    return (fixedPointNum == other.fixedPointNum);
}

bool	Fixed::operator!=(const Fixed& other) const
{
    return (fixedPointNum != other.fixedPointNum);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
    Fixed result(this->toFloat() + other.toFloat());
    return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
    Fixed result(this->toFloat() - other.toFloat());
    return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
    Fixed result(this->toFloat() * other.toFloat());
    return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
    Fixed result(this->toFloat() / other.toFloat());
    return (result);
}

Fixed&	Fixed::operator++(void)
{
    fixedPointNum++;
    return (*this);
}

Fixed	Fixed::operator++(int)
{
    Fixed oldValue(*this);
    fixedPointNum++;
    return (oldValue);
}

Fixed&	Fixed::operator--(void)
{
    fixedPointNum--;
    return (*this);
}

Fixed	Fixed::operator--(int)
{
    Fixed oldValue(*this);
    fixedPointNum--;
    return (oldValue);
}

Fixed&	Fixed::min(Fixed &fixed_1, Fixed &fixed_2)
{
    if (fixed_1 < fixed_2)
        return (fixed_1);
	else
        return (fixed_2);
}

const Fixed&	Fixed::min(const Fixed &fixed_1, const Fixed &fixed_2)
{
    if (fixed_1 < fixed_2)
        return (fixed_1);
	else
        return (fixed_2);
}

Fixed&	Fixed::max(Fixed &fixed_1, Fixed &fixed_2)
{
    if (fixed_1 > fixed_2)
        return (fixed_1);
	else
        return (fixed_2);
}

const Fixed&	Fixed::max(const Fixed &fixed_1, const Fixed &fixed_2)
{
    if (fixed_1 > fixed_2)
        return (fixed_1);
	else
        return (fixed_2);
}
