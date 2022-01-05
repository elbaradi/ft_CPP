#ifndef KAREN_HPP
# define KAREN_HPP

#include <string>

class	Karen
{
	private:
	
		void	_debug(void) const;
		void	_info(void) const;
		void	_warning(void) const;
		void	_error(void) const;

		typedef void (Karen::*PTR)(void) const;
		static const PTR	_pmf[4];
		static const std::string _messages[4];

	public:
		void	complain(std::string level);

	Karen(void);
	~Karen(void);
};

#endif
