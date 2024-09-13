/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:10:50 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/13 13:13:53 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP
# include "WrongAnimal.hpp"
# include <string>
# include <iostream>

class WrongDog : public WrongAnimal {
	public:
		WrongDog( void );
		~WrongDog( void );
		WrongDog( WrongDog const& src );
		WrongDog& operator= (WrongDog const& rhs);
		void makeSound( void ) const;
	private:
		std::string type;
};

#endif