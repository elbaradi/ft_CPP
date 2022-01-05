#include <string>

#include "Data.hpp"

Data::Data( void ) : _name("(null)"), _info("(null)") {
	return ;
}

Data::Data( std::string name ) : _name(name), _info("(null)") {
	return ;
}

Data::Data( const Data& src ) {
	*this = src;
}

Data& Data::operator=( const Data& other ) {
	if (this != &other)	{
		this->_info = other._info;
	}
	return *this;
}

const std::string& Data::getName( void ) const {
	return this->_name;
}

void Data::setInfo( const std::string& info ) {
	this->_info = info;
}

const std::string& Data::getInfo( void ) const {
	return this->_info;
}

Data::~Data( void ) {
	return ;
}

uintptr_t	serialize( Data* ptr ) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		deserialize( uintptr_t raw ) {
	return reinterpret_cast<Data *>(raw);
}
