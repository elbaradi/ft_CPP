#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int					_fvalue;
		static const int	_fbits;

	public:
		int		getRawBits( void ) const;
		void	setRawBits( const int raw );

		int		toInt( void ) const;
		float	toFloat( void ) const;

	Fixed( void );
	~Fixed( void );
	Fixed ( const int nbr );
	Fixed ( const float nbr );
	Fixed( const Fixed& src );

	Fixed& operator=( const Fixed& rhs );

	bool operator>( const Fixed& rhs ) const;
	bool operator<( const Fixed& rhs ) const;
	bool operator>=( const Fixed& rhs ) const;
	bool operator<=( const Fixed& rhs ) const;
	bool operator==( const Fixed& rhs ) const;
	bool operator!=( const Fixed& rhs ) const;

	Fixed operator+( const Fixed& rhs ) const;
	Fixed operator-( const Fixed& rhs ) const;
	Fixed operator*( const Fixed& rhs ) const;
	Fixed operator/( const Fixed& rhs ) const;

	Fixed& operator++( void );
	Fixed operator++( int );
	Fixed& operator--( void );
	Fixed operator--( int );

	static Fixed& min( Fixed& fp_1, Fixed& fp_2 );
	static const Fixed& min( const Fixed& fp_1, const Fixed& fp_2 );
	static Fixed& max( Fixed& fp_1, Fixed& fp_2 );
	static const Fixed& max( const Fixed& fp_1, const Fixed& fp_2 );
	
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

int isBitSet(int n, int k);

#endif
