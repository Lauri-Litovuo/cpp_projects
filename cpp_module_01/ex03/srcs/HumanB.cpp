/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:38:04 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/05 10:44:25 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = nullptr;
	return ;
}

HumanB::~HumanB()
{
	return ;
}
void HumanB::attack()
{
	if (this->_weapon == nullptr)
		std::cout << this->_name << " has no weapon" << std::endl;
	else
		std::cout << this->_name << " attacks withg their weapon " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
