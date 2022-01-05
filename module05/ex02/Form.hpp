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
		const std::string _target;
		bool _isSigned;

	protected:
		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};
		class UnsignedException : public std::exception {
			const char* what() const throw();
		};
		class UnauthorizedException : public std::exception {
			const char* what() const throw();
		};
		class AlreadySignedException : public std::exception {
			const char* what() const throw();
		};
	
	public:
		void beSigned( const Bureaucrat& bureaucrat );
		virtual void execute( Bureaucrat const & executor ) const = 0;
		bool canBeExecutedBy( Bureaucrat const & executor ) const;

	const std::string& getName( void ) const;
	int getGradeRequiredToSign( void ) const;
	int getGradeRequiredToExecute( void ) const;
	const std::string& getTarget( void ) const;
	int getIsSignedStatus( void ) const;

	Form( void );
	Form( std::string name, int gradeRequiredToSign, int gradeRequiredToExecute );
	Form( std::string name, int gradeRequiredToSign, int gradeRequiredToExecute, std::string target );
	Form( const Form& src );
	Form( std::string name, const Form& src );
	virtual ~Form( void );

	Form& operator=( const Form& other );
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif
