#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "* two arguments only *" << std::endl;
		return 0;
	}
	
	std::string	str(av[1]);
	ScalarConverter::convertType(str);
	return 0;
}
