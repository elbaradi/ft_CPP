#ifndef __ROBOTOMYREQUESTFORM_HPP__
# define __ROBOTOMYREQUESTFORM_HPP__

# include <string>

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:
		void execute( Bureaucrat const & executor ) const;
		
	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( const RobotomyRequestForm& src );
	~RobotomyRequestForm( void );

	RobotomyRequestForm& operator=( const RobotomyRequestForm& other );
};

#endif
