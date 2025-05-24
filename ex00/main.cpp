#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	ScalarConverter conv;
	std::string	str(av[1]);

	if (ac != 2)
		return 0;
	conv.convert(str);
	return (0)
}
