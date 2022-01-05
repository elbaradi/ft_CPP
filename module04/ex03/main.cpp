#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int functionozo( void ) {
	{
		ICharacter* tony = new Character( "tony" );
		ICharacter* willem = new Character( "willem" );
		AMateria* bolt1 = new Ice();
		AMateria* bolt2 = new Ice();
		AMateria* heal1 = new Cure();
		std::cout << "\n";

		tony->equip(bolt1);
		tony->equip(bolt2);
		willem->equip(heal1);
		std::cout << "\n";

		ICharacter* lapswans = new Character( *(Character*)tony );
		std::cout << "\n";

		tony->use(0, *willem);		// testing basic use functionality
		tony->use(1, *willem);		// testing basic use functionality
		willem->use(0, *willem);	// testing basic use functionality
		lapswans->use(0, *willem);	// testing use functionality after copy
		lapswans->use(3, *willem);	// testing use functionality on empty slot
		lapswans->use(9, *willem);	// testing use functionality on non-existing slot
		std::cout << "\n";

		delete tony;
		delete willem;
		delete lapswans;
		std::cout << "\n\n";
	}
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << "\n";

		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << "\n";

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		return 0;
	}
}

int main( void ) { 

	functionozo();
	system("leaks program");
	return 0;
}
