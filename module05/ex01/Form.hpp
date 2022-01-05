#ifndef __FORM_HPP__
# define __FORM_HPP__

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		const int _gradeRequiredToSign;
		const int _gradeRequiredToExecute;
		bool _isSigned;

	public:
		void beSigned( const Bureaucrat& bureaucrat );

	const std::string& getName( void ) const;
	int getGradeRequiredToSign( void ) const;
	int getGradeRequiredToExecute( void ) const;
	int getIsSignedStatus( void ) const;

	Form( void );
	Form( std::string name, int gradeRequiredToSign, int gradeRequiredToExecute );
	Form( const Form& src );
	Form( std::string name, const Form& src );
	~Form( void );

	Form& operator=( const Form& other );

	class GradeTooHighException : public std::exception {
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		const char* what() const throw();
	};
	class AlreadySignedException : public std::exception {
		const char* what() const throw();
	};
	
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif
