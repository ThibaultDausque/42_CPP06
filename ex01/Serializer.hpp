#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <iostream>

typedef struct Data
{
	int		age;
	std::string	name;
}	Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& cpy);

	public:
		Serializer&	operator=(const Serializer& src);
		~Serializer();
		static uintptr_t	serialize(Data *ptr);
		static Data*	deserialize(uintptr_t raw);
};

#endif
