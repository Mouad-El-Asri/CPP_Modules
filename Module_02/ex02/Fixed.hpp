#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					fixedPointNum;
		static const int	numFractionalBits = 8;

	public:
		Fixed();
		Fixed(const int intNum);
		Fixed(const float floatNum);
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int 				getRawBits(void) const;
		void 				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;

		bool				operator>(const Fixed &other) const;
		bool				operator<(const Fixed &other) const;
		bool				operator>=(const Fixed &other) const;
		bool				operator<=(const Fixed &other) const;
		bool				operator==(const Fixed &other) const;
		bool				operator!=(const Fixed &other) const;

		Fixed				operator+(const Fixed &other) const;
		Fixed				operator-(const Fixed &other) const;
		Fixed				operator*(const Fixed &other) const;
		Fixed				operator/(const Fixed &other) const;

		Fixed&				operator++(void);
		Fixed				operator++(int);
		Fixed&				operator--(void);
		Fixed				operator--(int);

		static Fixed&		min(Fixed &fixed_1, Fixed &fixed_2);
		static const Fixed& min(const Fixed &fixed_1, const Fixed &fixed_2);
		static Fixed&		max(Fixed &fixed_1, Fixed &fixed_2);
		static const Fixed& max(const Fixed &fixed_1, const Fixed &fixed_2);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif
