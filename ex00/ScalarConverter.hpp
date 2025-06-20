#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <iomanip>
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& cpy);

	public:
		ScalarConverter&	operator=(const ScalarConverter& src);
		~ScalarConverter();
		static bool	isChar(std::string& arg);
		static bool isInt(std::string& arg);
		static bool	isFloat(std::string& arg);
		static bool isDouble(std::string& arg);
		static void	convertType(std::string& arg);
		static bool	pseudoLiterals(std::string& arg, int flag);
};

#endif
