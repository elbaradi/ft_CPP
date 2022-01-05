#include "Array.hpp"
#include <string>
#include <iostream>

#define MAX_VAL 750

#define SIZE_INT_ARRAY 6
#define SMALLER_SIZE_INT_ARRAY 4
#define SIZE_STR_ARRAY 8


void function1( void ) {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    //Functionality test #1 (copy constructor)
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		std::cout << "Functionality test #1 (copy constructor): " << mirror[200] << ' ' << tmp[200] << ' ' << numbers[200] << ' ' << test[200] << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++) //Functionality test #2 ([]operator)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "Functionality test #2 ([]operator): didn't save the same value!!" << std::endl;
            return;
        }
    }
	std::cout << "Functionality test #2 ([]operator): success!" << std::endl;

    try // out of bounds test
    {
        numbers[-2] = 0;
    } catch(const std::exception& e) {
        std::cout << "Out of bounds test #1: success! ";
		std::cerr << e.what() << '\n';
    }

    try // out of bounds test
    {
        numbers[MAX_VAL] = 0;
    } catch(const std::exception& e) {
		std::cout << "Out of bounds test #2: success! ";
        std::cerr << e.what() << '\n';
    }

    delete [] mirror;//
    return;
}

void function2( void ) {
	Array<int> nonumbers; //Array<int> with size 0
	Array<int> numbers(MAX_VAL); //Array<int> with size MAX_VAL
    int* mirror = new int[MAX_VAL]; //Mirror int array of our array<int> with size MAX_VAL
    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++) //Populating Array<int> and the int array with random values
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

	nonumbers = numbers; //Testing the copy constructor to see if it correctly 'upsizes' the empty array<int> and copies the populated array<int>
	for (int i = 0; i < MAX_VAL; i++)
        numbers[i] = 0;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != nonumbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return;
        }
    }
	nonumbers = numbers;
	numbers = nonumbers;
    delete [] mirror;
    return;
}

int main(int, char**)
{
	function1();
	function2();
	system("leaks Array");

	{
		Array<int> intArray(SIZE_INT_ARRAY); //Creating and populating Array<int> (6, 11)
		for (int i = 0; i < SIZE_INT_ARRAY; i++) {
			intArray[i] = i + 6;
		}

		Array<std::string> strArray(SIZE_STR_ARRAY); //Creating and populating Array<string> (Line: 0, Line: 7)
		for (int i = 0; i < SIZE_STR_ARRAY; i++) {
			strArray[i] = "Line: " + std::to_string(i);
		}

		Array<int> anotherIntArray(SMALLER_SIZE_INT_ARRAY); //Creating and populating a smaller Array<int> (-12, -9)
		for (int i = 0; i < SMALLER_SIZE_INT_ARRAY; i++) {
			anotherIntArray[i] = i - 12;
		}
		std::cout << std::endl << std::endl;

		std::cout << "intArray: [";
		for (int i = 0; i < SIZE_INT_ARRAY; i++) {
			std::cout << intArray[i] << ' ';
		}
		std::cout << "]\n";

		std::cout << "strArray: [";
		for (int i = 0; i < SIZE_STR_ARRAY; i++) {
			std::cout << strArray[i] << ' ';
		}
		std::cout << "]\n";

		std::cout << "anotherIntArray: [";
		for (int i = 0; i < SMALLER_SIZE_INT_ARRAY; i++) {
			std::cout << anotherIntArray[i] << ' ';
		}
		std::cout << "]\n";

		intArray = anotherIntArray; //Testing to see if Array<int> 'downscales' and correctly copies a smaller Array<int>
		std::cout << "intArray: [";
		for (int i = 0; i < SMALLER_SIZE_INT_ARRAY; i++) {
			std::cout << intArray[i] << ' ';
		}
		std::cout << "]\n";
	}

	return 0;
}

