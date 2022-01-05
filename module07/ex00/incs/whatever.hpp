#ifndef __WHATEVER_HPP__
# define __WHATEVER_HPP__

template<typename T>
void swap(T& a, T& b) {
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
const T& max(const T& a, const T& b) {
	return ( (a >= b) ? a : b );
}

template<typename T>
const T& min(const T& a, const T& b) {
	return ( (a <= b) ? a : b );
}

#endif
