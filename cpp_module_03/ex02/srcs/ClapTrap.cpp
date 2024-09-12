/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:37:06 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/12 09:31:21 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
	this->_name = "Anon";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " is built!" << std::endl;
}
ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " is built!" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage)
{
	this->_name = name;
	this->_hitPoints = hitPoints;
	this->_energyPoints = energyPoints;
	this->_attackDamage = attackDamage;
	std::cout << "ClapTrap " << this->_name << " is built!" << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " is destroyed!" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &src)
{
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
}
ClapTrap& ClapTrap::operator=(const ClapTrap &rhs)
{
	if(this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}
void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy points!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return ;
	}
	if (this->_hitPoints <= amount)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << this->_hitPoints << " points of damage!" << std::endl;
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	std::cout << "ClapTrap " << this->_name << " has now " << this->_hitPoints << " hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy points!" << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	std::cout << "ClapTrap " << this->_name << " is repaired by " << amount << " points!" << std::endl;
	std::cout << "ClapTrap " << this->_name << " has now " << this->_hitPoints << " hit points left!" << std::endl;
}

void ClapTrap::setName(std::string name)
{
	this->_name = name;
}
void ClapTrap::setHitPoints(unsigned int hitPoints)
{
	this->_hitPoints = hitPoints;
}
void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	this->_energyPoints = energyPoints;
}
void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	this->_attackDamage = attackDamage;
}
std::string ClapTrap::getName() const
{
	return this->_name;
}
unsigned int ClapTrap::getHitPoints() const
{
	return this->_hitPoints;
}
unsigned int ClapTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}
unsigned int ClapTrap::getAttackDamage() const
{
	return this->_attackDamage;
}
