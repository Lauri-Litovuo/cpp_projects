/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:36:16 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/13 13:39:08 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat") {
	std::cout << "A WrongCat has been created" << std::endl;
	this->type = "WrongCat";
}


WrongCat::~WrongCat( void ) {
	std::cout << "A WrongCat has been killed" << std::endl;
}

WrongCat::WrongCat( WrongCat const& src) : WrongAnimal("WrongCat") {
	*this = src;
	std::cout << "A WrongCat has been duped" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const& rhs) {
	this->type = rhs.type;
	return *this;
}

void WrongCat::makeSound( void ) const {
	std::cout << "* WrongCat sounds *" << std::endl;
}

