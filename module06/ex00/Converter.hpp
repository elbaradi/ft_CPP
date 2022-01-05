#ifndef __CONVERTER_HPP__
# define __CONVERTER_HPP__

# include <string>

# define NUMBER_OF_TYPES 4

class Converter {

	enum e_inputType {
		NONE = -1,
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		UNRECOGNIZED
	};

	private:
		const std::string _input;
		const e_inputType _type;
		char _char;
		int	_int;
		float _float;
		double _double;

		bool _isChar( const std::string input );
		bool _isInt( const std::string input );
		bool _isFloat( const std::string input );
		bool _isDouble( const std::string input );

		void _printChar( bool canBeConverted );
		void _printInt( bool canBeConverted );
		void _printFloat( bool canBeConverted );
		void _printDouble( void );

		void _parseFromChar( void );
		void _parseFromInt( void );
		void _parseFromFloat( void );
		void _parseFromDouble( void );

		typedef bool (Converter::*PTR)( const std::string input );
		static PTR _pmf[NUMBER_OF_TYPES];
		
		typedef void (Converter::*PRINTR)( void );
		static PRINTR _printrf[NUMBER_OF_TYPES];

	public:
		const std::string& getInput( void );
		e_inputType getType( void );
		char getChar( void );
		int getInt( void );
		float getFloat( void );
		double getDouble( void );
		
		e_inputType identifyType( const std::string input );

		void print( void );

	Converter( void );
	Converter( std::string input );
	Converter( Converter& src );
	~Converter( void );

	Converter& operator=( const Converter& other );
};

#endif
