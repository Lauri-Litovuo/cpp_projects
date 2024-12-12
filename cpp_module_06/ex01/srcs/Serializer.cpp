#include "Serializer.hpp"
#include "Data.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
	if (ptr == nullptr)
		return 0;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	if ( raw == 0)
		return nullptr;
	return reinterpret_cast<Data *>(raw);
}

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return *this;
}
