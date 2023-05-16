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

		bool    operator>( const Fixed &rhs ) const ;
		bool    operator<( const Fixed &rhs ) const ;
		bool    operator>=( const Fixed &rhs ) const ;
		bool    operator<=( const Fixed &rhs ) const ;
		bool    operator==( const Fixed &rhs ) const ;
		bool    operator!=( const Fixed &rhs ) const ;

		Fixed   operator+( const Fixed &rhs ) const ;
		Fixed   operator-( const Fixed &rhs ) const ;
		Fixed   operator*( const Fixed &rhs ) const ;
		Fixed   operator/( const Fixed &rhs ) const ;

		Fixed&  operator++( void );
		Fixed   operator++( int );
		Fixed&  operator--( void );
		Fixed   operator--( int );

		static Fixed& min( Fixed &a, Fixed &b );
		static const Fixed& min( const Fixed &a, const Fixed &b );
		static Fixed& max( Fixed &a, Fixed &b );
		static const Fixed& max( const Fixed &a, const Fixed &b );
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


#endif
