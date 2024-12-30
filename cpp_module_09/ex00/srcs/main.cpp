#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./bitcoin_exchange <filename>" << std::endl;
		return 1;
	}
	try{
		BitcoinExchange exchange(av[1]);
		exchange.run();
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}