/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:10:50 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/13 13:13:58 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include <string>
# include <iostream>

class Cat : public Animal {
	public:
		Cat( void );
		~Cat( void );
		Cat( Cat const& src );
		Cat& operator= (Cat const& rhs);
		void makeSound( void ) const;
	private:
		std::string type;
};

#endif