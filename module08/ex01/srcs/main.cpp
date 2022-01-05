#include <climits>
#include <iostream>
#include <vector>

#include "span.hpp"

int main( void ) {
	{
		Span sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	{	// No storage space test, should return exception
		Span sp(0);
		try {
			sp.addNumber(1);
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
	}
	{	
		Span sp(5);
		sp.addNumber(INT_MAX - 1);
		try {	// Too little elements to find span, should return exception
			std::cout << sp.shortestSpan() << std::endl;
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		
		sp.addNumber(INT_MIN); // Testing if overflow is correctly accounted for in span calculations, both should return 4294967294
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		sp.addNumber(89);
		sp.addNumber(10000);
		sp.addNumber(89);
		std::cout << sp.shortestSpan() << std::endl; // Should be zero (89, 89)
		std::cout << sp.longestSpan() << std::endl; // Should still be 4294967294

		std::cout << std::endl;
	}
	{	// Big size test
		Span sp(15050);
		std::vector<int> arr;

		for(int i = 0; i < 12000; i++) {
			if (i % 2)
				arr.push_back(i * i + i);
			else
				arr.push_back(-i * i + i);
    	}
		sp.addNumbers(arr.begin(), arr.end()); // using iterators to fill sp
		sp.addNumber(12001); 
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << std::endl;
	}
	return 0;
}
