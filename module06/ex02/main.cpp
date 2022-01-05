#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

class Base {public: virtual ~Base( void ) {} };
class A: public Base {};
class B: public Base {};
class C: public Base {};

Base* generate( void ) {
	srand(time(NULL));
	int random_nbr;
	random_nbr = rand();
	
	if (random_nbr % 3 == 0)
		return new A;
	else if	(random_nbr % 3 == 1)
		return new B;
	else
		return new C;
}

void identify( Base* p ) {
    A* ptrToObjectA = dynamic_cast<A*>(p);
    if (ptrToObjectA != NULL) {
    	std::cout << "Real type of p: A" << std::endl;
		return ; 
	}

    B* ptrToObjectB = dynamic_cast<B*>(p);
    if (ptrToObjectB != NULL) {
    	std::cout << "Real type of p: B" << std::endl;
		return;
	}

	C* ptrToObjectC = dynamic_cast<C*>(p);
    if (ptrToObjectC != NULL) {
    	std::cout << "Real type of p: C" << std::endl;
	}
	return;
}

void identify( Base& p ) {
	try {
	    A& refToObjectA = dynamic_cast<A&>(p);
        std::cout << "Real type of p: A" << std::endl;
		(void)refToObjectA;
		return;
    } catch (std::bad_cast &bc) {};

	try {
	    B& refToObjectB = dynamic_cast<B&>(p);
        std::cout << "Real type of p: B" << std::endl;
		(void)refToObjectB;
		return;
    } catch (std::bad_cast &bc) {};

	try {
	    C& refToObjectC = dynamic_cast<C&>(p);
        std::cout << "Real type of p: C" << std::endl;
		(void)refToObjectC;
    } catch (std::bad_cast &bc) {};
	return;
}

int main( void ) {
	Base* Obj = generate();

	identify(Obj); // void identify( Base* p )

	identify(*Obj); // void identify( Base& p )

	return 0;
}
