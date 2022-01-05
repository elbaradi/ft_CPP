#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define NUM_ANIMALS 12

static int	functionada()
{
	{
		std::cout << "\nDemonstrating deep Brain copy" << std::endl;
		Dog dog;
		dog.getBrain()->setIdea(0, "Why do people think a straw has 2 holes?");
		Dog copy(dog);

		std::cout << "\n     first idea of dog: " << dog.getBrain()->getIdea(0) << std::endl;
		std::cout << "first idea of dog copy: " << copy.getBrain()->getIdea(0) << std::endl;

		std::cout << "\n\n " << std::endl;

		const int n_dogs = NUM_ANIMALS / 2;
		Animal*	  animals[NUM_ANIMALS];

		for (size_t i = 0; i < n_dogs; i++) {
			std::cout << i << '\n';
			animals[i] = new Dog();
		}
		for (size_t i = n_dogs; i < NUM_ANIMALS; i++) {
			std::cout << i << '\n';
			animals[i] = new Cat();
		}

		for (size_t i = 0; i < NUM_ANIMALS; i++) {
			std::cout << i << '\n';
			delete animals[i];
		}
		std::cout << "\n\n\n";
	}

	{
		Animal* meta[10];

		for(int i = 0; i < 5; i++){
			meta[i] = new Dog();
		}
		for(int i = 5; i < 10; i++){
			meta[i] = new Cat();
		}
		meta[5]->getBrain()->setIdea( 0, "this is a string" );
		std::cout << meta[5]->getBrain()->getIdea(0) << std::endl;
		*(meta[6]) = *(meta[5]);
		std::cout << meta[6]->getBrain()->getIdea(0) << std::endl;
		meta[5]->getBrain()->setIdea( 0, "nothing" );
		std::cout << meta[5]->getBrain()->getIdea(0) << std::endl;
		std::cout << meta[6]->getBrain()->getIdea(0) << std::endl;
		for(int i = 0; i < 10; i++){
			delete meta[i];
		}
		return 0;
	}
}


int main()
{
	functionada();
	system("leaks program");
	return 0;
}
