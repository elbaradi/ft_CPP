#include <string>
#include <iostream>

#include "Converter.hpp"

int main( int argc, char **argv ) {
	if (argc == 2) {
		Converter converter(argv[1]);
		converter.print();
	}
	return 0;
}
