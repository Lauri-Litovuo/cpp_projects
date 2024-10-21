/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:03:10 by llitovuo          #+#    #+#             */
/*   Updated: 2024/10/21 20:09:13 by llitovuo         ###   ########.fr       */
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
		virtual void makeSound( void ) const = 0; //this makes the class abstract because pure virtual function

	protected:
		std::string type;
};

#endif