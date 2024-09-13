/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:10:50 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/13 13:13:53 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include <string>
# include <iostream>

class Dog : public Animal {
	public:
		Dog( void );
		~Dog( void );
		Dog( Dog const& src );
		Dog& operator= (Dog const& rhs);
		void makeSound( void ) const;
	private:
		std::string type;
};

#endif