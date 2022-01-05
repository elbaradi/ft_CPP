#include <iostream>

void	caps(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			::*str -= 32;
		str++;
	}
}

int	main(int argc, char **argv)
{
	
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		argv++;
		while (*argv)
		{
			caps(*argv);
			std::cout << *argv;
			argv++;
		}
	}
	std::cout << std::endl;
	return 0;
}
