/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:20:20 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/05 10:25:21 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon{

public:
	
	Weapon(std::string type);
	~Weapon();
	std::string getType();
	void setType(std::string type);

private:
	
	std::string _type;
};

#endif