#ifndef SCALARCOVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>

class ScalarConverter
{
	private:
		char	a;
		int		b;
		float	c;
		double	d;

	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& cpy);
		~ScalarConverter()
		ScalarConverter&	operator=(const ScalarConverter& src);
		static void	convert(const std::string& literal);
		char	getChar();
		int		getInt();
		float	getFloat();
		double	getDouble();
		int		isInt(std::string literal);
		int		isFloat(std::string literal);
		int		isChar(std::string literal);
};

#endif
