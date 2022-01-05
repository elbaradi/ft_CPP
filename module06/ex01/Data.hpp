#ifndef __DATA_HPP__
# define __DATA_HPP__

class Data
{
	private:
		const std::string _name;
		std::string _info;

	public:
		const std::string& getName( void ) const;
		void setInfo( const std::string& info );
		const std::string& getInfo( void ) const;

	Data( void );
	Data( std::string name );
	Data( const Data& src );
	~Data( void );

	Data& operator=( const Data& other );
};

uintptr_t	serialize( Data* ptr );
Data*		deserialize( uintptr_t raw );

#endif
