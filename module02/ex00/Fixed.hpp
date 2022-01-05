#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	private:
		int					_fvalue;
		static const int	_fbits;

	public:
		int		getRawBits( void ) const;
		void	setRawBits( const int raw );

	Fixed( void );
	~Fixed( void );
	Fixed( const Fixed& src );

	Fixed& operator=( const Fixed& rhs );
};

#endif
