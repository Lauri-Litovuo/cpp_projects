/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:03:13 by llitovuo          #+#    #+#             */
/*   Updated: 2024/10/23 10:00:20 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void ) {
	this->type = "AAnimal";
	std::cout << "Some creature is borned" << std::endl;
}

AAnimal::AAnimal ( std::string type ) : type(type) {
	std::cout << "An AAnimal: ";
}

AAnimal::~AAnimal( void ) {
	if (this->type == "AAnimal")
		std::cout << "An creature has died."<< std::endl;
	else
		std::cout << "Subclass called an AAnimal deconstructor" << std::endl;
}

AAnimal::AAnimal(AAnimal const& src ) {
	*this = src;
}

AAnimal& AAnimal::operator= (AAnimal const& rhs) {
	this->type = rhs.type;
	return *this;
}

std::string AAnimal::getType( void ) const {
	return this->type;
}

void AAnimal::setType( std::string type ) {
	this->type = type;
}

void AAnimal::makeSound( void ) const {
	std::cout << "*AAnimal sounds *" << std::endl;
}
