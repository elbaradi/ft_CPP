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
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

int isBitSet(int n, int k);

#endif
