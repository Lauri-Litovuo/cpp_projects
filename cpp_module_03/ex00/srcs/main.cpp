/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:15:47 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/11 14:02:45 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap claptrap1;
	ClapTrap claptrap2("ClapTrap2");
	
	claptrap1.attack("ClapTrap2");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);
	
	claptrap1.attack("ClapTrap2");
	claptrap2.takeDamage(5);
	claptrap1.attack("ClapTrap2");
	claptrap2.takeDamage(5);
	
	claptrap1.attack("ClapTrap2");
	claptrap2.takeDamage(5);

	claptrap1.beRepaired(3);
	claptrap2.beRepaired(3);
	claptrap1.beRepaired(3);
	claptrap1.beRepaired(3);
	claptrap1.beRepaired(3);
	claptrap1.beRepaired(3);
	claptrap1.beRepaired(3);
	claptrap1.beRepaired(3);
	claptrap1.beRepaired(3);
	return (0);
}