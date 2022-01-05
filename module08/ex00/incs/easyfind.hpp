#pragma once

#include <algorithm>    // std::find
#include <exception>

class NotFoundException : public std::exception {
		const char* what() const throw() {
            return "value not found";
        };
};

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), value);
    if ( it == container.end() )
        throw NotFoundException();
    return it;
}
