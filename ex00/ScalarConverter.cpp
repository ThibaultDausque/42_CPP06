#include "ScalarConverter.hpp"

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

int	ScalarConverter::isInt(std::string literal)
{
	if (literal.empty())
		return 0;
	for (int i = 0; i < literal.size(); i++)
	{
		if (literal[i] < 30 || literal[i] > 57)
			return 0;
	}
	return 1;
}

int	ScalarConverter::isChar(std::string& literal)
{
	if (literal.size() > 1 || literal.empty())
		return 0;
	else if (literal[0] < 32 || literal[0] > 126)
		return 0;
	return 1;
}

char	ScalarConverter::getChar()
{
	return this->a;
}

int	ScalarConverter::getInt()
{
	return this->b;
}

float	ScalarConverter::getFloat()
{
	return this->c;
}

double	ScalarConverter::getDouble()
{
	return this->d;
}

static void	ScalarConverter::convert(const std::string& literal)
{
	if (isChar(literal))
	{
		this->a = literal;
		std::cout << "char: \'"<< this->a << "\'" << std::endl;
	}
	if (isInt(literal))
	{
		this->b = atoi(literal);
		std::cout << "int: \'"<< this->b << "\'" << std::endl;
	}
}


