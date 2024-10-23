/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:10:50 by llitovuo          #+#    #+#             */
/*   Updated: 2024/10/23 09:58:29 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"
# include <string>
# include <iostream>

class Cat : public AAnimal {
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
