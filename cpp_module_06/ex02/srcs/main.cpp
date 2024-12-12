#include "Identify.hpp"
#include "Base.hpp"

int main()
{
	Base *base = generate();
	Base &ref = *base;
	identify(base);
	identify(ref);
	delete base;
}
