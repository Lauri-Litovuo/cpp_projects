/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:10:42 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/13 13:16:12 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"

Dog::Dog( void ): Animal("Dog") {
	std::cout << "A Dog has been created" << std::endl;
	this->type = "Dog";
}

Dog::~Dog( void ) {
	std::cout << "A Dog has been killed" << std::endl;
}

Dog::Dog( Dog const& src) : Animal("Dog") {
	*this = src;
	std::cout << "A Dog has been duped" << std::endl;
}

Dog& Dog::operator=(Dog const& rhs) {
	this->type = rhs.type;
	return *this;
}

void Dog::makeSound( void ) const {
	std::cout << "* Dog sounds *" << std::endl;
}

