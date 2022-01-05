#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::cout << "String created (str): " << str << std::endl;

	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "String address (&str): " << &str << std::endl;
	std::cout << "String address (stringPTR): " << stringPTR << std::endl;
	std::cout << "String address (&stringREF): " << &stringREF << std::endl;

	std::cout << "String (*stringPTR) : " << *stringPTR << std::endl;
	std::cout << "String (stringREF) : " << stringREF << std::endl;

	return 0;
}
