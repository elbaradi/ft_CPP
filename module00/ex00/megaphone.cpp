#include <iostream>

void	caps(char *str)
{
	for (; *str; str++)
		if (*str >= 'a' && *str <= 'z')
			*str += - 'a' + 'A';
}

int	main(int argc, char **argv)
{
	
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (argv++; *argv; argv++)
		{
			caps(*argv);
			std::cout << *argv;
		}
	}
	std::cout << std::endl;
	return 0;
}
