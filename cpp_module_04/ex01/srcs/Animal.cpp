/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:03:13 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/13 13:30:16 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) {
	this->type = "Animal";
	std::cout << "Some creature is borned" << std::endl;
}

Animal::Animal ( std::string type ) : type(type) {
	std::cout << "An Animal: ";
}

Animal::~Animal( void ) {
	if (this->type == "Animal")
		std::cout << "An creature has died."<< std::endl;
	else
		std::cout << "Subclass called an Animal deconstructor" << std::endl;
}

Animal::Animal( Animal const& src ) {
	*this = src;
}

Animal& Animal::operator= (Animal const& rhs) {
	this->type = rhs.type;
	return *this;
}

std::string Animal::getType( void ) const {
	return this->type;
}

void Animal::setType( std::string type ) {
	this->type = type;
}

void Animal::makeSound( void ) const {
	std::cout << "* Animal sounds *" << std::endl;
}
