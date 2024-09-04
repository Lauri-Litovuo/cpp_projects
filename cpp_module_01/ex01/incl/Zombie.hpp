/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:46:23 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/04 15:52:37 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie{

public:
	Zombie( void );
	Zombie( std::string );
	~Zombie();
	void	announce( void );
	void	setName( std::string name );

private:

	std::string _name;
};

#endif
