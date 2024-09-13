/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:10:50 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/13 13:13:58 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"
# include <string>
# include <iostream>

class WrongCat : public WrongAnimal {
	public:
		WrongCat( void );
		~WrongCat( void );
		WrongCat( WrongCat const& src );
		WrongCat& operator= (WrongCat const& rhs);
		void makeSound( void ) const;
	private:
		std::string type;
};

#endif