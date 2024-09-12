/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:19:39 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/12 09:42:16 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap("Anonymous FragTrap", 100, 100, 30) {
	std::cout << "A FragTrap built!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "A FragTrap named "<< name << " built" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "A FragTrap " << this->_name << " destroyed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	_guardGateMode = copy._guardGateMode;
	std::cout << "A FragTrap " << this->_name << " cloned!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &rhs) {
	ClapTrap::operator=(rhs);
	_guardGateMode = rhs._guardGateMode;
	std::cout << "A FragTrap assigned!" << std::endl;
	return *this;
}

void FragTrap::attack(const std::string& target) {
	if (this->_energyPoints == 0) {
		std::cout << "FragTrap " << this->_name << " is out of energy points!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void FragTrap::HighFivesGuys() {
	if (this->_hitPoints == 0) {
		std::cout << "FragTrap " << this->_name << " is already destroyed!" << std::endl;
	}
	else {
		std::cout << "FragTrap " << this->_name << " high fives Traps!" << std::endl;
	}
}
