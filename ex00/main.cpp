#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	ScalarConverter conv;
	std::string	str(av[1]);

	ScalarConverter::convert(str);
	return (0);
}
