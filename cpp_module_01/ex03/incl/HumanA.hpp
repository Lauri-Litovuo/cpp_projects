/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:20:26 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/05 10:29:10 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <string>
# include "Weapon.hpp"

class HumanA{

public:
	
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
	
private:
	
	std::string _name;
	Weapon &_weapon;

};

#endif