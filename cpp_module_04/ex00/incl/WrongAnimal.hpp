/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:03:10 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/13 13:17:29 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>
# include <iostream>


class WrongAnimal {
	public:
		WrongAnimal( void );
		WrongAnimal( std::string type );
		virtual ~WrongAnimal( void );
		WrongAnimal( WrongAnimal const& src );
		WrongAnimal& operator= (WrongAnimal const& rhs);
		std::string getType( void ) const;
		void setType( std::string type );
		void makeSound( void ) const;

	protected:
		std::string type;
};

#endif
