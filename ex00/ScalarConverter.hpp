#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <iomanip>

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
		~ScalarConverter();
		ScalarConverter&	operator=(const ScalarConverter& src);
		static void	convert(const std::string& literal);
		char	getChar() const;
		int		getInt() const;
		float	getFloat() const;
		double	getDouble() const;
		int		isIntFloatDouble(const std::string& literal);
		int		isChar(const std::string& literal);
		int		pseudoLiterals(const std::string& literal);
};

#endif
