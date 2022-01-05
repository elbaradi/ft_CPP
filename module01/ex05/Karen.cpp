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
	std::cout << "DEBUG: Messages in this level contain extensive contextual information. They are mostly used for problem diagnosis.\n";
}

void	Karen::_info(void) const
{
	std::cout << "INFO: These messages contain some contextual information to help trace execution in a production environment.\n";
}

void	Karen::_warning(void) const
{
	std::cout << "WARNING: A warning message indicates a potential problem in the system. The system is able to handle the problem by itself or to proceed with this problem anyway.\n";
}

void	Karen::_error(void) const
{
	std::cout << "ERROR: An error message indicates a serious problem in the system. The problem is usually non-recoverable and requires manual intervention.\n";
}

void	Karen::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (!level.compare(_messages[i]))
		{
			(this->*_pmf[i])();
			break ;
		}
		if (i == 3)
			std::cout << "Instruction \"" << level << "\" is unrecognized.\n";
	}
}
