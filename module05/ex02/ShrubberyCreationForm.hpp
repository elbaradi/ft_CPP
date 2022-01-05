#ifndef __SHRUBBERYCREATIONFORM_HPP__
# define __SHRUBBERYCREATIONFORM_HPP__

# include <string>

# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		void _createShrubberyFile( void ) const;
		static const std::string& _getTreeString( void );

	public:
		void execute( Bureaucrat const & executor ) const;

	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( const ShrubberyCreationForm& src );
	~ShrubberyCreationForm( void );

	ShrubberyCreationForm& operator=( const ShrubberyCreationForm& other );
};

#endif
