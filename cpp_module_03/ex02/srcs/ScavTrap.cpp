/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:19:39 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/12 09:32:44 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap("Anonymous ScavTrap", 100, 50, 20) {
	std::cout << "A ScavTrap built!" << std::endl;
	_guardGateMode = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "A ScavTrap named "<< name << " built" << std::endl;
	_guardGateMode = false;
}

ScavTrap::~ScavTrap() {
	std::cout << "A ScavTrap " << this->_name << " destroyed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
	_guardGateMode = copy._guardGateMode;
	std::cout << "A ScavTrap " << this->_name << " cloned!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &rhs) {
	ClapTrap::operator=(rhs);
	_guardGateMode = rhs._guardGateMode;
	std::cout << "A ScavTrap assigned!" << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (this->_energyPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " is out of energy points!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void ScavTrap::guardGate() {
	if (this->_guardGateMode == false && this->_hitPoints > 0) {
		std::cout << "ScavTrap " << this->_name << " has entered Gate keeper mode!" << std::endl;
		_guardGateMode = true;
	}
	else if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " is already destroyed!" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << this->_name << " has exited Gate keeper mode!" << std::endl;
		_guardGateMode = false;
	}
}



