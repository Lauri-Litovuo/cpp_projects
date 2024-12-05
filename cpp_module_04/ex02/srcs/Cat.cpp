/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:10:42 by llitovuo          #+#    #+#             */
/*   Updated: 2024/10/23 10:01:39 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : AAnimal("Cat") {
	Brain *newBrain = new Brain();
	this->brain = newBrain;
	std::cout << "A Cat has been created" << std::endl;
	this->type = "Cat";
}


Cat::~Cat( void ) {
	delete this->brain;
	std::cout << "A Cat has been killed" << std::endl;
}


Cat::Cat( Cat const& src) : AAnimal("Cat") {
	*this = src;
	this->brain = new Brain(*src.brain);
	std::cout << "A Cat has been duped" << std::endl;
}

Cat& Cat::operator=(Cat const& rhs) {
	this->type = rhs.type;
	this->brain = rhs.brain;
	return *this;
}

void Cat::makeSound( void ) const {
	std::cout << "* Cat sounds *" << std::endl;
}

void Cat::setBrain(int index, std::string idea) {
	this->brain->setIdea(index, idea);
}

std::string Cat::getBrain(int index) const {
	return this->brain->getIdea(index);
}
