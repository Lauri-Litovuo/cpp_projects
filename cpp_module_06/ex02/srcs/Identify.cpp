#include "Identify.hpp"

Base * generate(void){
    Base *random = nullptr;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 2);

	switch (dis(gen))
	{
		case 0:
			random = new A();
			break;
		case 1:
			random = new B();
			break;
		case 2:
			random = new C();
			break;
	}
	return (random);
}


void identify(Base* p){
    {
        A *ptrA = dynamic_cast<A*>(p);
        if (ptrA)
        {
            std::cout << "Type: A" << std::endl;
            return ;
        }
    }
    {
        B *ptrB = dynamic_cast<B*>(p);
        if (ptrB)
        {
            std::cout << "Type: B" << std::endl;
            return ;
        }
    }
    {
        C *ptrC = dynamic_cast<C*>(p);
        if (ptrC)
        {
            std::cout << "Type: C" << std::endl;
            return ;
        }
    }
    std::cout << "Type: Base" << std::endl;
}

void identify(Base& p){
    try{
        A &ptrA = dynamic_cast<A&>(p);
        (void)ptrA;
        std::cout << "Type: A" << std::endl;
        return ;
    } catch (std::bad_cast &e){}

    try{
        B &ptrB = dynamic_cast<B&>(p);
        (void)ptrB;
        std::cout << "Type: B" << std::endl;
        return ;
    } catch (std::bad_cast &e){}

    try{
        C &ptrC = dynamic_cast<C&>(p);
        (void)ptrC;
        std::cout << "Type: C" << std::endl;
        return ;
    } catch (std::bad_cast &e){}

    std::cout << "Type: Base" << std::endl;

}
