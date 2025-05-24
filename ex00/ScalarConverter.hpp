#ifndef SCALARCOVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

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
};

#endif
