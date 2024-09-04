/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:44:31 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/04 16:09:41 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( void )
{
	this->_name = "";
}

Zombie::Zombie( std::string name) : _name(name)
{
	announce();
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": * Sounds of dying *" << std::endl;
	return ;
}
void Zombie::announce( void ){

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName( std::string name ){
	this->_name = name;
}

