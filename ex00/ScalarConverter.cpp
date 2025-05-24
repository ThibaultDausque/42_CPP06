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

static void	convert(const std::string& literal)
{

}


