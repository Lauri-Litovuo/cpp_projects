/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:23:41 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/05 10:25:05 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	_type = type;
}
Weapon::~Weapon()
{
	return ;
}
std::string Weapon::getType()
{
	return (this->_type);
}
void Weapon::setType(std::string type)
{
	this->_type = type;
}
