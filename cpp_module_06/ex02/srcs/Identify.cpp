#include "Identify.hpp"
#include <iostream>

Base * generate(void){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 2);
	Base *random = nullptr;
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

template <typename T>
eType getType() {
	return Unknown;
};


template <>
eType getType<Base>() {
    return BaseType;
};


template <>
eType getType<A>() {
    return AType;
};

template <>
eType getType<B>() {
    return BType;
};

template <>
eType getType<C>() {
    return CType;
};


void identify(Base* p){
    eType type = getType<std::decay_t<decltype(*p)>>();
    switch (type) {
        case AType:
            std::cout << "Type: A" << std::endl;
            break;
        case BType:
            std::cout << "Type: B" << std::endl;
            break;
        case CType:
            std::cout << "Type: C" << std::endl;
            break;
        case BaseType:
            std::cout << "Type: Base" << std::endl;
            break;
        case Unknown:
        default:
            std::cout << "Unknown type" << std::endl;
            break;
    }
}

void identify(Base& p){

}