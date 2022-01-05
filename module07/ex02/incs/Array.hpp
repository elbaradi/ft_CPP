#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

#include <exception>
#include <iostream>

template <typename T>
class Array {
	private:
		T *_array;
		unsigned int _size;
	
	public:
		unsigned int size( ) const { return _size; }

		Array( void ) : _array(NULL), _size(0) { }
		Array( unsigned int size ) : _array(NULL), _size(size) {
			if (size)
				this->_array = new T[size];
		}
		Array( const Array& src ) : _array(NULL), _size(0) { *this = src; }
		~Array( void ) { delete[] this->_array; }
		
		Array<T>& operator=( const Array<T>& other ) {
			if (this != &other) {
				delete[] this->_array;
				this->_array = NULL;
				this->_size = other.size();
				if (this->_size)
					this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++ ) {
					this->_array[i] = other._array[i];
				}
			}
			return *this;
		}
		T& operator[]( size_t index ) {
			if (index >= _size || index < 0) {
				throw std::exception();
			} else {
				return *(_array + index);
			}
		}
};

#endif
