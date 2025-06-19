#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

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
		return *this;
	return *this;
}

bool	ScalarConverter::isChar(std::string& arg)
{
	if (arg.size() != 1 && std::atoi(arg.c_str()) == 0)
		return false;
	if (arg[0] >= 32 && arg[0] <= 126)
		return true;
	else if (std::atoi(arg.c_str()) != 0 && std::atoi(arg.c_str()) >= 32
		&& std::atoi(arg.c_str()) <= 126)
		return true;
	return true;
}

bool	ScalarConverter::isInt(std::string& arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < 48 || arg[i] > 57)
			return false;
		i++;
	}
	return true;
}

bool	ScalarConverter::isFloat(std::string& arg)
{
	int		i;

	i = 0;
	while (arg[i] && arg[i] != '.')
	{
		if (arg[i] < 48 || arg[i] > 57)
			return false;
		i++;
	}
	if (arg[i] == '.')
	{
		while (arg[i] && arg[i] != 'f')
		{
			if (arg[i] < 48 || arg[i] > 57)
				return false;
			i++;
		}
	}
	if (arg[i] == 'f' && arg[i + 1] != '\0')
		return false;
	return true;
}


bool	ScalarConverter::isDouble(std::string& arg)
{
	int		i;

	i = 0;
	while (arg[i] && arg[i] != '.')
	{
		if (arg[i] < 48 || arg[i] > 57)
			return false;
		i++;
	}
	if (arg[i] == '.')
	{
		while (arg[i])
		{
			if (arg[i] < 48 || arg[i] > 57)
				return false;
			i++;
		}
	}
	return true;
}

void	ScalarConverter::convertType(std::string& arg)
{
	if (isChar(arg))
	{
		char c = static_cast<char>(arg[0]);
		std::cout << "char: " << c << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;
	if (isInt(arg))
	{
		int nb = static_cast<int>(std::atoi(arg.c_str()));
		std::cout << "int: " << nb << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;
	if (isFloat(arg))
	{
		float	ft = static_cast<float>(std::atof(arg.c_str()));
		std::cout << "float: " << ft << std::endl;
	}
	else
		std::cout << "float: impossible" << std::endl;
	if (isDouble(arg))
	{
		double	db = static_cast<double>(std::atof(arg.c_str()));
		std::cout << "double: " << db << std::endl;
	}
	else
		std::cout << "double: impossible" << std::endl;
}


