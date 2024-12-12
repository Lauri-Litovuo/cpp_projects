#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
	{
    Data originalData = {"test", 42};
    Data* originalPointer = &originalData;

    uintptr_t raw = Serializer::serialize(originalPointer);
    Data* deserializedPointer = Serializer::deserialize(raw);
    if (originalPointer == deserializedPointer) 
	{
        std::cout << "Serialization and Deserialization Successful!" << std::endl;
        std::cout << "Name and value in desialized pointer: " << deserializedPointer->name << ", " << deserializedPointer->value << std::endl;
    } 
	else 
        std::cout << "Error: Pointers do not match." << std::endl;
	}

	{
		Data *ptr = nullptr;
		uintptr_t raw = Serializer::serialize(ptr);
		Data *deserialized = Serializer::deserialize(raw);
		if (deserialized == nullptr)
			std::cout << "It is a nullpointer" << std::endl;
		else
			std::cout << "It's not a nullpointer" << std::endl;
	}
    return 0;
}