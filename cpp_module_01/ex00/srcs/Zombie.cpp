/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:44:31 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/04 15:10:37 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( std::string name) : _name(name)
{
	announce();
}

Zombie::~Zombie()
{
	std::cout << "Deconstruct of zombie: " << this->_name << std::endl;
	return ;
}
void Zombie::announce( void ){

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

