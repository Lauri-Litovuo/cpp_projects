/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:10:50 by llitovuo          #+#    #+#             */
/*   Updated: 2024/10/21 20:11:49 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"
# include <string>
# include <iostream>

class Cat : public Animal {
	public:
		Cat( void );
		~Cat( void );
		Cat( Cat const& src );
		Cat& operator= (Cat const& rhs);
		void makeSound( void ) const override; //needs override as it is a virtual function
		void setBrain(int index, std::string idea);
		std::string getBrain(int index) const;
		
	private:
		std::string type;
		Brain *brain;
};

#endif