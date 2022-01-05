#include <cmath> //isinf(x), isnan(x), ceil(x), ceilf(x), isfinite(x)
#include <limits> //std::numeric_limits
#include <sstream> //std::stringstream (Thanks Joppe!)
#include <string>
#include <iostream>

#include "Converter.hpp"

Converter::PTR	Converter::_pmf[NUMBER_OF_TYPES] = { &Converter::_isChar, &Converter::_isInt, &Converter::_isFloat, &Converter::_isDouble };
Converter::PRINTR	Converter::_printrf[NUMBER_OF_TYPES] = { &Converter::_parseFromChar, &Converter::_parseFromInt, &Converter::_parseFromFloat, &Converter::_parseFromDouble };

Converter::Converter( void ) : _input("null"), _type(NONE), _char(0), _int(0), _float(0), _double(0) {
	return ;
}

Converter::Converter( std::string input ) : _input(input), _type(identifyType(input)) {
	return ;
}

Converter::Converter( Converter& src ) : _input(src._input), _type(src._type) {
	*this = src;
	return ;
}

Converter::~Converter( void ) {
	return ;
}

const std::string& Converter::getInput( void ) {
	return this->_input;
}

Converter::e_inputType Converter::getType( void ) {
	return this->_type;
}

Converter::e_inputType Converter::identifyType( const std::string input ) {
	for (int i = 0; i < 4; i++) {
		if ((this->*_pmf[i])(input) == true)
			return static_cast<e_inputType>(i);
	}
	return UNRECOGNIZED;
}

bool Converter::_isChar( const std::string input ) {
	if (input.length() == 3 && input.front() == '\'' && input.back() == '\'') {
		this->_char = static_cast<char>(input[1]);
		return true;
	}
	else
		return false;
}

bool Converter::_isInt( const std::string input ) {	
	std::size_t lastNonDigitPosition = input.find_last_not_of("0123456789");
	bool inputConsistsOfDigitsOnly = (std::isdigit(input.front()) && lastNonDigitPosition == std::string::npos);
	bool inputIsSigned = (input.front() == '-' || input.front() == '+');
	bool signedInputConsistsOfDigitsOnly = (inputIsSigned && std::isdigit(input[1]) && lastNonDigitPosition == 0);

	if (inputConsistsOfDigitsOnly || signedInputConsistsOfDigitsOnly) {
		try {
			this->_int = std::stoi(input);
			return true;
		} catch (const std::exception& e) {
			return false;
		}
	}
	else
		return false;
}

bool Converter::_isFloat( const std::string input ) {
	bool inputIsPseudoLiteral = (input == "inff" || input == "+inff" || input == "-inff" || input == "nanf");

	std::size_t firstLowercaseF = input.find_first_of("f");
	bool inputContainsASingleLowercaseFWhichIsPositionedAtTheEnd = (firstLowercaseF != std::string::npos && firstLowercaseF == input.size() - 1);

	std::size_t lastSign = input.find_last_of("+-");
	bool inputContainsNoMoreThanOneSignWhichWouldBePositionedAtTheStart = (lastSign == std::string::npos || lastSign == 0);
	
	std::size_t firstDecimalPoint = input.find_first_of(".");
	std::size_t lastDecimalPoint = input.find_last_of(".");
	bool inputContainsNoMoreThanOneDecimalPoint = (firstDecimalPoint == lastDecimalPoint);

	std::size_t firstNonValidChar = input.find_first_not_of("+-.f0123456789");
	bool inputConsistsOfOnlyValidChars = (firstNonValidChar == std::string::npos);

	if (inputIsPseudoLiteral || (inputContainsASingleLowercaseFWhichIsPositionedAtTheEnd && inputConsistsOfOnlyValidChars && inputContainsNoMoreThanOneSignWhichWouldBePositionedAtTheStart && inputContainsNoMoreThanOneDecimalPoint)) {
		try {
			this->_float = std::stof(input);
			return true;
		} catch (const std::exception& e) {
			return false;
		}
	}
	else
		return false;
}

bool Converter::_isDouble( const std::string input ) {
	bool inputIsPseudoLiteral = (input == "inf" || input == "+inf" || input == "-inf" || input == "nan");

	std::size_t lastSign = input.find_last_of("+-");
	bool inputContainsNoMoreThanOneSignWhichWouldBePositionedAtTheStart = (lastSign == std::string::npos || lastSign == 0);
	
	std::size_t firstDecimalPoint = input.find_first_of(".");
	std::size_t lastDecimalPoint = input.find_last_of(".");
	bool inputContainsNoMoreThanOneDecimalPoint = (firstDecimalPoint == lastDecimalPoint);

	std::size_t firstNonValidChar = input.find_first_not_of("+-.0123456789");
	bool inputConsistsOfOnlyValidChars = (firstNonValidChar == std::string::npos);
	
	if (inputIsPseudoLiteral || (inputConsistsOfOnlyValidChars && inputContainsNoMoreThanOneSignWhichWouldBePositionedAtTheStart && inputContainsNoMoreThanOneDecimalPoint)) {
		try {
			this->_double = std::stod(input);
			return true;
		} catch (const std::exception& e) {
			return false;
		}
	}
	else
		return false;
}

void Converter::_printChar( bool canBeConverted ) {
	std::cout << "char: ";
	if (canBeConverted == false )
		std::cout << "impossible";
	else if (std::isprint(_char) == false)
		std::cout << "Non displayable";
	else
		std::cout << '\'' << _char << '\'';
	std::cout << std::endl;
}

void Converter::_printInt( bool canBeConverted ) {
	std::cout << "int: ";
	if (canBeConverted == false )
		std::cout << "impossible";
	else
		std::cout << _int;
	std::cout << std::endl;
}

void Converter::_printFloat( bool canBeConverted ) {
	std::stringstream ss;
	ss << _float;
	std::cout << "float: ";
	if (canBeConverted == false )
		std::cout << "impossible";
	else if (std::isfinite(_float) && _float == ceilf(_float) && (ss.str()).find("e") == std::string::npos)
		std::cout << _float << ".0f";
	else
		std::cout << _float << 'f';
	std::cout << std::endl;
}

void Converter::_printDouble( void ) {
	std::stringstream ss;
	ss << _double;
	std::cout << "double: ";
	if (std::isfinite(_double) && _double == ceil(_double) && (ss.str()).find("e") == std::string::npos)
		std::cout << _double << ".0";
	else
		std::cout << _double;
	std::cout << std::endl;
}

void Converter::_parseFromChar( void ) {
	bool canBeConvertedFromChar = true;
	_double = static_cast<double>(_char);
	_float = static_cast<float>(_char);
	_int = static_cast<int>(_char);

	_printChar(canBeConvertedFromChar);
	_printInt(canBeConvertedFromChar);
	_printFloat(canBeConvertedFromChar);
	_printDouble();
}

void Converter::_parseFromInt( void ) {
	bool canBeConvertedFromInt = true;
	_double = static_cast<double>(_int);
	_float = static_cast<float>(_int);

	canBeConvertedFromInt = (_int >= std::numeric_limits<char>::min() && _int <= std::numeric_limits<char>::max());
	if (canBeConvertedFromInt)
		_char = static_cast<int>(_int);

	_printChar(canBeConvertedFromInt);

	canBeConvertedFromInt = true;
	_printInt(canBeConvertedFromInt);
	_printFloat(canBeConvertedFromInt);
	_printDouble();
}

void Converter::_parseFromFloat( void ) {
	bool canBeConvertedFromFloat = true;
	_double = static_cast<double>(_float);

	canBeConvertedFromFloat = (_float >= std::numeric_limits<char>::min() && _float <= std::numeric_limits<char>::max());
	if (canBeConvertedFromFloat)
		_char = static_cast<char>(_float);
	_printChar(canBeConvertedFromFloat);

	canBeConvertedFromFloat = (_float >= std::numeric_limits<int>::min() && _float <= std::numeric_limits<int>::max());
	if (canBeConvertedFromFloat)
		_int = static_cast<int>(_float);
	_printInt(canBeConvertedFromFloat);

	canBeConvertedFromFloat = true;
	_printFloat(canBeConvertedFromFloat);
	_printDouble();
}

void Converter::_parseFromDouble( void ) {
	bool canBeConvertedFromDouble = (_double >= std::numeric_limits<char>::min() && _double <= std::numeric_limits<char>::max());
	if (canBeConvertedFromDouble)
		_char = static_cast<char>(_double);
	_printChar(canBeConvertedFromDouble);

	canBeConvertedFromDouble = (_double >= std::numeric_limits<int>::min() && _double <= std::numeric_limits<int>::max());
	if (canBeConvertedFromDouble)
		_int = static_cast<int>(_double);
	_printInt(canBeConvertedFromDouble);

	canBeConvertedFromDouble = (_double == 0 || (_double <= -std::numeric_limits<float>::min() && _double >= -std::numeric_limits<float>::max()) || (_double >= std::numeric_limits<float>::min() && _double <= std::numeric_limits<float>::max()) || std::isnan(_double) || std::isinf(_double));
	if (canBeConvertedFromDouble)
		_float = static_cast<float>(_double);
	_printFloat(canBeConvertedFromDouble);

	canBeConvertedFromDouble = true;
	_printDouble();
}

void Converter::print( void ) {
	if (_type != NONE && _type != UNRECOGNIZED) {
		(this->*_printrf[static_cast<int>(_type)])();
	} else if (_type == UNRECOGNIZED) {
		std::cout << "Input has not been recognized as a char, int, float or double literal value\n";
	} else
		std::cout << "Converter has not been given an input string upon initialization\n";
}

Converter& Converter::operator=( const Converter& other ) {
	if (this != &other && this->_type == other._type) {
		this->_char = other._char;
		this->_int = other._int;
		this->_float = other._float;
		this->_double = other._double;
	}
	return *this;
}
