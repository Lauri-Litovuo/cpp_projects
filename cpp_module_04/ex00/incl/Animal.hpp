/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:03:10 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/13 13:17:29 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>


class Animal {
	public:
		Animal( void );
		Animal( std::string type );
		virtual ~Animal( void );
		Animal( Animal const& src );
		Animal& operator= (Animal const& rhs);
		std::string getType( void ) const;
		void setType( std::string type );
		virtual void makeSound( void ) const;

	protected:
		std::string type;
};

#endif