#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	meta->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n\n";

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongI = new WrongCat();

	std::cout << wrongI->getType() << " " << std::endl;

	wrongMeta->makeSound();
	wrongI->makeSound(); //will output the cat sound!

	delete wrongMeta;
	delete wrongI;
}
