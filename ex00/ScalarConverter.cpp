#include "ScalarConverter.hpp"
#include <iomanip>
#include <ios>

ScalarConverter::ScalarConverter()
{
	this->a = 0; //char
	this->b = 0; //int
	this->c = 0; //float
	this->d = 0; //double
}

ScalarConverter::ScalarConverter(const ScalarConverter& cpy)
{
	*this = cpy;
}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& src)
{
	if (this != &src)
	{
		this->a = src.getChar();
		this->b = src.getInt();
		this->c = src.getFloat();
		this->d = src.getDouble();
	}
	return *this;
}

int	ScalarConverter::isIntFloatDouble(const std::string& literal)
{
	int		i;

	i = 0;
	if (literal[0] == '-')
		i++;
	if (literal.empty())
		return 0;
	while (literal[i] && literal[i] >= 48 && literal[i] <= 57)
	{
		if (literal[i] < 48 || literal[i] > 57)
			return 0;
		i++;
	}
	if (literal[i] == 0)
		return 1;
	else if (literal[i] == '.' && literal[i + 1] >= 48 && literal[i + 1] <= 57)
	{
		i++;
		if (literal[i + 1] == 0)
			return 1;
		if (literal[i + 1] == 0 || literal[i + 1] == 'f')
		{
			i++;
			if (literal[i + 1] == 0)
				return 1;
		}
	}
	return 0;
}

int	ScalarConverter::isChar(const std::string& literal)
{
	if (literal.empty())
		return 0;
	if (atoi(literal.c_str()) != 0 && (atoi(literal.c_str()) >= 32 || atoi(literal.c_str()) <= 126))
		return 1;
	else if (literal.length() == 1 && (literal[0] >= 32 || literal[0] <= 126))
		return 2;
	return 0;
}

char	ScalarConverter::getChar() const
{
	return this->a;
}

int	ScalarConverter::getInt() const
{
	return this->b;
}

float	ScalarConverter::getFloat() const
{
	return this->c;
}

double	ScalarConverter::getDouble() const
{
	return this->d;
}

int	ScalarConverter::pseudoLiterals(const std::string& literal)
{
	if (literal == "nan")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return 1;
	}
	if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return 1;
	}
	if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return 1;
	}
	return 0;
}

void	ScalarConverter::convert(const std::string& literal)
{
	ScalarConverter obj;

	if (obj.pseudoLiterals(literal))
		return ;
	if (obj.isChar(literal) == 1)
	{
		if (atoi(literal.c_str()) < 32 || atoi(literal.c_str()) > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
		{
			obj.a = atoi(literal.c_str());
			std::cout << "char: \'"<< obj.a << "\'" << std::endl;
		}
	}
	else if (obj.isChar(literal) == 2)
	{
		obj.a = literal[0];
		std::cout << "char: \'" << obj.a << "\'" << std::endl;
	}
	else
		std::cout <<  "char: impossible" << std::endl;
	if (obj.isIntFloatDouble(literal))
	{
		obj.b = atoi(literal.c_str());
		obj.c =	atof(literal.c_str());
		obj.d = obj.c;
		std::cout << "int: \'" << obj.b << "\'" << std::endl;
		std::cout << "float: \'" << std::fixed << std::setprecision(1) << obj.c << "f\'" << std::endl;
		std::cout << "double: \'" << std::fixed << std::setprecision(1) << obj.d << "\'" << std::endl;
	}
	else 
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}


