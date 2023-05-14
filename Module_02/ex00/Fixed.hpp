#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int					fixedPointNum;
		static const int	numFractionalBits = 8;
	public:
		Fixed();
		Fixed(int fixedPointNum);
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int 				getRawBits(void) const;
		void 				setRawBits(int const raw);
};

#endif
