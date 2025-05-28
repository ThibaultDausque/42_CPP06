#include "Serializer.hpp"

int	main()
{
	Data*	data = new Data();
	uintptr_t	serialize_data;
	Data*	deserialize_data = new Data();


	data->name = "toto";
	data->age = 24;

	deserialize_data->name = "null";
	deserialize_data->age = 0;

	serialize_data = Serializer::serialize(data);
	std::cout << "--- SERIALIZE DATA ---" << std::endl;
	std::cout << "Data adress: " << data << std::endl;
	std::cout << "data int: " << data->age << std::endl;
	std::cout << "data string: " << data->name << std::endl;
	std::cout << std::endl;

	deserialize_data = Serializer::deserialize(serialize_data);
	std::cout << "--- DESERIALIZE DATA ---" << std::endl;
	std::cout << "Data adress: " << deserialize_data << std::endl;
	std::cout << "data int: " << deserialize_data->age << std::endl;
	std::cout << "data string: " << deserialize_data->name << std::endl;

	return 0;
}
