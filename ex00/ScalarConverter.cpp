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

int	isDigit(std::string& arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < 48 || arg[i] > 57)
			return 0;
		i++;
	}
	return 1;
}

bool	ScalarConverter::isChar(std::string& arg)
{
	if (std::atoi(arg.c_str()) >= 32 && std::atoi(arg.c_str()) <= 126)
		return true;
	if ((arg.size() == 1 && (arg[0] < 32 || arg[0] > 126))
		|| (isDigit(arg) && (std::atoi(arg.c_str()) < 32 || std::atoi(arg.c_str()) > 126)))
	{
		std::cout << "char: Non displayable" << std::endl;
		return false;
	}
	else if (arg.size() == 1 && arg[0] >= 32 && arg[0] <= 126)
		return true;
	std::cout << "char: impossible" << std::endl;
	return false;
}

bool	ScalarConverter::isFloat(std::string& arg)
{
	int		i;

	i = 0;
	if (arg[0] == '-')
		i++;
	while (arg[i] && arg[i] != '.')
	{
		if (arg[i] < 48 || arg[i] > 57)
			return false;
		i++;
	}
	if (arg[i] == '.')
	{
		i++;
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
	if (arg[0] == '-')
		i++;
	while (arg[i] && arg[i] != '.')
	{
		if (arg[i] < 48 || arg[i] > 57)
			return false;
		i++;
	}
	if (arg[i] == '.')
	{
		i++;
		while (arg[i])
		{
			if ((arg[i] < 48 || arg[i] > 57) && arg[i] != 'f')
				return false;
			i++;
		}
	}
	return true;
}

void	ScalarConverter::convertType(std::string& arg)
{
	int		flag;

	if (isChar(arg))
	{
		char	c;

		if (std::atoi(arg.c_str()) >= 32 && std::atoi(arg.c_str()) <= 126)
		{
			c = static_cast<char>(std::atoi(arg.c_str()));
			std::cout << "char: \'" << c << "\'" << std::endl;
		}
		else
		{
			c = static_cast<char>(arg[0]);
			std::cout << "char: \'" << c << "\'" << std::endl;
		}
	}
	if (isFloat(arg))
	{
		int nb = static_cast<int>(std::atoi(arg.c_str()));
		std::cout << "int: " << nb << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;
	if (isFloat(arg))
	{
		float	ft = static_cast<float>(std::atof(arg.c_str()));
		std::cout << "float: " << std::fixed << std::setprecision(1) << ft << "f" << std::endl;
	}
	else
	{
		flag = 1;
		if (!pseudoLiterals(arg, flag))
			std::cout << "float: impossible" << std::endl;
	}
	if (isDouble(arg))
	{
		double	db = static_cast<double>(std::atof(arg.c_str()));
		std::cout << "double: " << db << std::endl;
	}
	else
	{
		flag = 2;
		if (!pseudoLiterals(arg, flag))
			std::cout << "double: impossible" << std::endl;
	}
}

bool	ScalarConverter::pseudoLiterals(std::string& arg, int flag)
{
	if ((arg == "-inff" || arg == "-inf") && flag == 1)
	{
		float	neg_inf = -std::numeric_limits<float>::infinity();
		std::cout << "float: " << neg_inf << "f" << std::endl;
		return true;
	}
	else if ((arg == "+inff" || arg == "+inf") && flag == 1)
	{
		float	pos_inf = std::numeric_limits<float>::infinity();
		std::cout << "float: " << pos_inf << "f" << std::endl;
		return true;
	}
	else if ((arg == "nanf" || arg == "nan") && flag == 1)
	{
		float	nan_val = std::numeric_limits<float>::quiet_NaN();
		std::cout << "float: " << nan_val << "f" << std::endl;
		return true;
	}
	else if ((arg == "-inf" || arg == "-inff") && flag == 2)
	{
		double	db_ninf = -std::numeric_limits<double>::infinity();
		std::cout << "double: " << db_ninf << std::endl;
		return true;
	}
	else if ((arg == "+inf" || arg == "+inff") && flag == 2)
	{
		double	db_inf = std::numeric_limits<double>::infinity();
		std::cout << "double: " << db_inf << std::endl;
		return true;
	}
	else if ((arg == "nan" || arg == "nanf") && flag == 2)
	{
		double db_nan = std::numeric_limits<double>::quiet_NaN();
		std::cout << "double: " << db_nan << std::endl;
		return true;
	}
	return false;
}

