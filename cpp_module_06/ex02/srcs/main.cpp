#include "Identify.hpp"
#include "Base.hpp"

int main()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << " \nROUND " << i + 1 << std::endl;
		Base *base = generate();
		Base &ref = *base;
		identify(base);
		identify(ref);
		delete base;
	}
}
