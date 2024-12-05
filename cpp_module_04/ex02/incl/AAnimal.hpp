/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:03:10 by llitovuo          #+#    #+#             */
/*   Updated: 2024/10/21 20:09:13 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP
# include <string>
# include <iostream>


class AAnimal {
	public:
		AAnimal( void );
		AAnimal( std::string type );
		virtual ~AAnimal( void );
		AAnimal( AAnimal const& src );
		AAnimal& operator= (AAnimal const& rhs);
		std::string getType( void ) const;
		void setType( std::string type );
		virtual void makeSound( void ) const = 0; //this makes the class abstract because pure virtual function

	protected:
		std::string type;
};

#endif
