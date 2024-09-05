/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:44:28 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/05 10:04:06 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name );

int	main(int ac, char **av)
{
	int nbZombies = 10;
	std::string zombieName = "runningZombie";

	if (ac > 1)
	{
		if (atoi(av[1]) < 0)
		{
			std::cout << "Number of zombies must be positive" << std::endl;
			return (1);
		}
		nbZombies = atoi(av[1]);
		if (ac > 2)
			zombieName = av[2];
	}
	std::cout << "\nMaking horde of " << nbZombies << " of " << zombieName << "s" << std::endl;
	Zombie *theHorde = zombieHorde(nbZombies, zombieName);
	for (int i = 0; i < nbZombies; i++)
			theHorde[i].announce();
	std::cout << "\nDestroying the zombies" << std::endl;
	delete [] (theHorde);
	return (0);
}
