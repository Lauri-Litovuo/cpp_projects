/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:10:42 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/13 13:03:09 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
	std::cout << "A Cat has been created" << std::endl;
	this->type = "Cat";
}


Cat::~Cat( void ) {
	std::cout << "A Cat has been killed" << std::endl;
}


Cat::Cat( Cat const& src) : Animal("Cat") {
	*this = src;
	std::cout << "A Cat has been duped" << std::endl;
}

Cat& Cat::operator=(Cat const& rhs) {
	this->type = rhs.type;
	return *this;
}

void Cat::makeSound( void ) const {
	std::cout << "* Cat sounds *" << std::endl;
}

