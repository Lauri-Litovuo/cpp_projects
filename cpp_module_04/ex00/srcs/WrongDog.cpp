/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:36:10 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/13 13:36:13 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/WrongDog.hpp"

WrongDog::WrongDog( void ): WrongAnimal("WrongDog") {
	std::cout << "A WrongDog has been created" << std::endl;
	this->type = "WrongDog";
}

WrongDog::~WrongDog( void ) {
	std::cout << "A WrongDog has been killed" << std::endl;
}

WrongDog::WrongDog( WrongDog const& src) : WrongAnimal("WrongDog") {
	*this = src;
	std::cout << "A WrongDog has been duped" << std::endl;
}

WrongDog& WrongDog::operator=(WrongDog const& rhs) {
	this->type = rhs.type;
	return *this;
}

void WrongDog::makeSound( void ) const {
	std::cout << "* WrongDog sounds *" << std::endl;
}

