#include <cctype>
#include <iostream>
#include <string>
#include "Karen.hpp"

const Karen::PTR	Karen::_pmf[4] = { &Karen::_debug, &Karen::_info, &Karen::_warning, &Karen::_error };
const std::string Karen::_messages[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Karen::Karen(void)
{
	return ;
}

Karen::~Karen(void)
{
	return ;
}

void	Karen::_debug(void) const
{
	std::cout << "[ DEBUG ]\nMessages in this level contain extensive contextual information. They are mostly used for problem diagnosis.\n\n";
}

void	Karen::_info(void) const
{
	std::cout << "[ INFO ]\nThese messages contain some contextual information to help trace execution in a production environment.\n\n";
}

void	Karen::_warning(void) const
{
	std::cout << "[ WARNING ]\nA warning message indicates a potential problem in the system. The system is able to handle the problem by itself or to proceed with this problem anyway.\n\n";
}

void	Karen::_error(void) const
{
	std::cout << "[ ERROR ]\nAn error message indicates a serious problem in the system. The problem is usually non-recoverable and requires manual intervention.\n\n";
}

void	Karen::complain(std::string level)
{
	int	i = 3;

	for (; i >= 0; i--)
	{
		if (!level.compare(_messages[i]))
		{
			for (; i < 4; i++)
				(this->*_pmf[i])();
			break ;
		}
	}
	if (i == -1)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
