#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base*	generate(void)
{
	int		random;

	random = std::rand() % 3;
	if (random == 0)
	{
		std::cout << "--- A ---" << std::endl;
		return new A();
	}
	else if (random == 1)
	{
		std::cout << "--- B ---" << std::endl;
		return new B();
	}
	else if (random == 2)
	{
		std::cout << "--- C ---" << std::endl;
		return new C();
	}
	std::cout << "error: random number fail" << std::endl;
	return NULL;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type: C" << std::endl;
	else
		std::cout << "error: Type doesn't exist" << std::endl;
}

void	identify(Base& p)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		try
		{
			if (i == 0)
				std::cout << "Type: A" << std::endl;
		}
		catch (std::bad_cast& e)
		{
			std::cout << "error" << std::endl;
		}
	}
}

int	main()
{
	std::cout << "* p* *" << std::endl;
	identify(*generate());
	identify(*generate());
	identify(*generate());

	std::cout << "* p& *" << std::endl;
	identify(generate());

}
