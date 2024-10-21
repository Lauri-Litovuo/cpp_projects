/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:10:50 by llitovuo          #+#    #+#             */
/*   Updated: 2024/10/21 19:42:55 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include <string>
# include <iostream>
# include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog( void );
		~Dog( void );
		Dog( Dog const& src );
		Dog& operator= (Dog const& rhs);
		void makeSound( void ) const;
		void setBrain(int index, std::string idea);
		std::string getBrain(int index) const;

	private:
		std::string type;
		Brain *brain;
};

#endif