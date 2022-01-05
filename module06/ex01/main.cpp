#include <iostream>

#include "Data.hpp"

int main( void ) {
	Data *job = new Data("Job");

	job->setInfo("Hello, I'm a data structure.");

	std::cout << job->getName() << " [" << job <<  "]: " << job->getInfo() << std::endl << std::endl;

	std::cout << "Now we serialize the data structure, and turn its address into an unsigned integer:\n";
	uintptr_t job_serialized = serialize(job);
	std::cout << job_serialized << std::endl << std::endl;

	std::cout << "Now we deserialize the unsigned integer, and turn it back into the address of the data structure, and we show that we can once again access it:\n";
	Data *job_deserialized = deserialize(job_serialized);
	std::cout << job_deserialized->getName() << " [" << job <<  "]: " << job_deserialized->getInfo() << std::endl;

	return 0;
}
