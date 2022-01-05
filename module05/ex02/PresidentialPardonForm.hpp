#ifndef __PRESIDENTIALPARDONFORM_HPP__
# define __PRESIDENTIALPARDONFORM_HPP__

# include <string>

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		void execute( Bureaucrat const & executor ) const;

	PresidentialPardonForm( void );
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( const PresidentialPardonForm& src );
	~PresidentialPardonForm( void );

	PresidentialPardonForm& operator=( const PresidentialPardonForm& other );
};

#endif
