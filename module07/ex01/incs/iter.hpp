#ifndef __ITER_HPP__
# define __ITER_HPP__

# include <iostream>

template <typename T>
void iter(T array[], size_t size, void (*f)(const T&)) {
	for (size_t i = 0; i < size; i++) {
		f(array[i]);
	}
}

template <typename T>
void printElement(const T& element) {
	std::cout << element << std::endl;
}

#endif
