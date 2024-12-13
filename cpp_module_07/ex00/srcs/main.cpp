#include <iostream>
#include <string>
#include "whatever.hpp"
#include <limits>


int main( void ) {
	{
		std::cout << "::::::::: Testing with subject main ::::::::::" << std::endl;
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		std::cout << "\n::::::::: Testing with custom main ::::::::::" << std::endl;

		double a = 2.2, b = 3.3;
		std::cout << "a = " << a << ", b = " << b << " before swapping" << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << " after swapping" << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::cout << "swapping same" << std::endl;
		::swap(a, a);
		std::cout << "success" << std::endl;
		std::cout << "changing a to 3.3" << std::endl;
		a = 3.3;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "";
		std::string d = "";
		std::cout << "c = " << c << ", d = " << d << " before swapping" << std::endl;
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << " after swapping" << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

		std::cout << "changing c to \"chaine2\"" << std::endl;
		c = "chaine2";
		std::cout << "c = " << c << ", d = " << d << " before swapping" << std::endl;
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << " after swapping" << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

		double nan = std::numeric_limits<double>::quiet_NaN();
        double inf = std::numeric_limits<double>::infinity();
        double neg_inf = -std::numeric_limits<double>::infinity();

		std::cout << "min(NaN, 1.0) = " << ::min(nan, 1.0) << std::endl;
        std::cout << "max(NaN, 1.0) = " << ::max(nan, 1.0) << std::endl;
        std::cout << "min(inf, 1.0) = " << ::min(inf, 1.0) << std::endl;
        std::cout << "max(inf, 1.0) = " << ::max(inf, 1.0) << std::endl;
        std::cout << "min(neg_inf, 1.0) = " << ::min(neg_inf, 1.0) << std::endl;
        std::cout << "max(neg_inf, 1.0) = " << ::max(neg_inf, 1.0) << std::endl;
		std::cout << "max(0.0, 0.0) = " << ::max(0.0, 0.0) << std::endl;
		std::cout << "min(0.0, 0.0) = " << ::min(0.0, 0.0) << std::endl;
	}
	return 0;
}