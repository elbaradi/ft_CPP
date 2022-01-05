#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

# include <exception>
# include <iostream>
# include <string>

# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int	_grade;

	class GradeTooHighException : public std::exception {
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		const char* what() const throw();
	};

	public:
		void signForm( Form& form );
		void executeForm( Form const & form );

		void setGrade( int grade );
		void incrementGrade( void );
		void decrementGrade( void );

	std::string const & getName( void ) const;
	int getGrade( void ) const;

	Bureaucrat( void );
	Bureaucrat( std::string name );
	Bureaucrat( int grade );
	Bureaucrat( std::string name, int grade );
	Bureaucrat( const Bureaucrat& src );
	~Bureaucrat( void );

	Bureaucrat& operator=( const Bureaucrat& other );
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
