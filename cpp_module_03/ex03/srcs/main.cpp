/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:15:47 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/12 14:02:26 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	/*{
	ClapTrap claptrap1;
	ClapTrap claptrap2("ClapTrap2");
	ScavTrap scavtrap1;
	ScavTrap scavtrap2("ScavTrap2");
	
	claptrap1.attack("ClapTrap2");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);
	
	scavtrap1.attack("ScavTrap2");
	scavtrap2.takeDamage(5);
	scavtrap2.beRepaired(3);
	
	scavtrap1.guardGate();
	scavtrap2.guardGate();
	scavtrap1.guardGate();
	scavtrap2.guardGate();
	}

	{
	FragTrap fragtrap1;
	FragTrap fragtrap2("FragTrap2");
	
	fragtrap1.attack("FragTrap2");
	fragtrap2.takeDamage(5);
	fragtrap2.beRepaired(3);
	
	fragtrap1.HighFivesGuys();
	fragtrap2.HighFivesGuys();
	}*/
	{
	DiamondTrap diamondtrap1;
	
	diamondtrap1.attack("Someone");
	diamondtrap1.whoAmI();
	diamondtrap1.HighFivesGuys();
	diamondtrap1.guardGate();
	}
	
	return (0);
}