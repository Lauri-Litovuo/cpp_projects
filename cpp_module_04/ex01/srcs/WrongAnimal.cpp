/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:03:13 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/13 13:30:16 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) {
	this->type = "WrongAnimal";
	std::cout << "Some creature is borned" << std::endl;
}

WrongAnimal::WrongAnimal ( std::string type ) : type(type) {
	std::cout << "An WrongAnimal: ";
}

WrongAnimal::~WrongAnimal( void ) {
	if (this->type == "WrongAnimal")
		std::cout << "An creature has died."<< std::endl;
	else
		std::cout << "Subclass called an WrongAnimal deconstructor" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const& src ) {
	*this = src;
}

WrongAnimal& WrongAnimal::operator= (WrongAnimal const& rhs) {
	this->type = rhs.type;
	return *this;
}

std::string WrongAnimal::getType( void ) const {
	return this->type;
}

void WrongAnimal::setType( std::string type ) {
	this->type = type;
}

void WrongAnimal::makeSound( void ) const {
	std::cout << "* WrongAnimal sounds *" << std::endl;
}
