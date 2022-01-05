#include <exception>
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Unnamed bureaucrat"), _grade(150) {
	return ;
}

Bureaucrat::Bureaucrat( std::string name ) : _name(name), _grade(150) {
	return ;
}

Bureaucrat::Bureaucrat( int grade ) : _name("Unnamed bureaucrat") {
	setGrade(grade);
	return ;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name) {
	setGrade(grade);
	return ;
}

Bureaucrat::~Bureaucrat( void ) {
	return ;
}

Bureaucrat::Bureaucrat( const Bureaucrat& src ) : _name(src.getName()) {
	*this = src;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other ) {
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

void Bureaucrat::signForm( Form& form ) {
	form.beSigned(*this);
}

std::string const & Bureaucrat::getName( void ) const {
	return this->_name;
}

int Bureaucrat::getGrade( void ) const {
	return _grade;
}

void Bureaucrat::setGrade( int grade ) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	else {
		this->_grade = grade;
	}
}

void Bureaucrat::incrementGrade( void ) {
	this->setGrade(this->_grade - 1);
}

void Bureaucrat::decrementGrade( void ) {
	this->setGrade(this->_grade + 1);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "grade too low";
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs) {
	o << rhs.getName() << ", grade " << rhs.getGrade() << ".\n";
	return o;
}
