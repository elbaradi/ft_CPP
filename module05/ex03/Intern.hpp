#ifndef __INTERN_HPP__
# define __INTERN_HPP__

# include <string>

# include "Form.hpp"

class Intern
{
	private:
		Form*	_makeShrubberyCreationForm( std::string target ) const;
		Form*	_makeRobotomyRequestForm( std::string target ) const;
		Form*	_makePresidentialPardonForm( std::string target ) const;

		typedef Form* (Intern::*PTR)( std::string target ) const;
		static PTR _pmf[3];
		static const std::string _formTypes[3];

	public:
		Form* makeForm( std::string type, std::string target ) const;
	
	Intern( void );
	Intern( const Intern& src );
	~Intern( void );

	Intern& operator=( const Intern& other );
};

#endif
