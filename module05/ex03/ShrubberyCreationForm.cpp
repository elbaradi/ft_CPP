#include <string>
#include <fstream>

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("shrubbery creation", 145, 137, "unidentified target") {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form("shrubbery creation", 145, 137, target) {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& src ) : Form(src) {
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	return ;
}

const std::string& ShrubberyCreationForm::_getTreeString( void ) {
	static const std::string tree = "\
             _{\\ _{\\{\\/}/}/}__\n\
            {/{/\\}{/{/\\}(\\}{/\\} _\n\
           {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n\
        {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n\
       {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n\
      _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n\
     {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n\
     _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n\
    {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n\
     {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n\
      {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n\
     {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n\
      {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n\
        {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n\
         (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n\
           {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n\
            {/{\\{\\{\\/}/}{\\{\\\\}/}\n\
             {){/ {\\/}{\\/} \\}\\}\n\
             (_)  \\.-\'.-/\n\
         __...--- |\'-.-\'| --...__\n\
  _...--\"   .-\'   |\'-.-\'|  \' -.  \"\"--..__\n\
-\"    \' .  . \'    |.\'-._| \'  . .  \'   jro\n\
.  \'-  \'    .--\'  | \'-.\'|    .  \'  . \'\n\
         \' ..     |\'-_.-|\n\
 .  \'  .       _.-|-._ -|-._  .  \'  .\n\
             .\'   |\'- .-|   \'.\n\
 ..-\'   \' .  \'.   `-._.-´   .\'  \'  - .\n\
  .-\' \'        \'-._______.-\'     \'  .\n\
       .      ~,\n\
   .       .   |\\   .    \' \'-.\n\
   ___________/  \\____________\n\
  /  Why is it, when you want \\\n\
 |  something, it is so damn   |\n\
 |    much work to get it?     |\n\
  \\___________________________/\n\
	";

	return tree;
}

void ShrubberyCreationForm::_createShrubberyFile( void ) const {
	const std::string filename = getTarget() + "_shrubbery";
	std::ofstream	of(filename);

	if (of.is_open())
	{
		of << _getTreeString();
    	of.close();
  	}
  	else
		std::cout << "Error: unable to open " << filename << std::endl;
}

void ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {
	if (canBeExecutedBy(executor) == true)
		_createShrubberyFile();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other ) {
	(void)other;
	return *this;
}
