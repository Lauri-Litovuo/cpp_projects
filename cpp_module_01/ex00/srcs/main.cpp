/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:44:28 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/04 15:10:45 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int	main(){
	Zombie zombie("Stack_Zombie_1");
	Zombie *heapZombie = newZombie("HeapZombie");
	randomChump("StackZombie2");
	delete (heapZombie);
	return (0);
}
