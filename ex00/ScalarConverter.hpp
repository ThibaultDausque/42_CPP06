#ifndef SCALARCONVERTER_HPP
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
		~ScalarConverter();
		ScalarConverter&	operator=(const ScalarConverter& src);
		static void	convert(const std::string& literal);
		char	getChar() const;
		int		getInt() const;
		float	getFloat() const;
		double	getDouble() const;
		int		isInt(std::string& literal);
		int		isFloat(std::string& literal);
		int		isChar(std::string& literal);
};

#endif
