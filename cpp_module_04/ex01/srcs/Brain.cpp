/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:44:36 by llitovuo          #+#    #+#             */
/*   Updated: 2024/10/21 17:43:30 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Brain.hpp"

Brain::Brain( void ) {
	std::cout << "A Brain has been created" << std::endl;
}

Brain::~Brain( void ) {
	std::cout << "A Brain has been shut down" << std::endl;
}

Brain::Brain( Brain const& src) {
	*this = src;
	std::cout << "A Brain has been duped" << std::endl;
}

Brain& Brain::operator=(Brain const& rhs) {
	for(int i = 0; i < 100; i++) {
		if (rhs.ideas[i].empty())
			this->ideas[i] = "";
		else
			this->ideas[i] = rhs.ideas[i];
	}
	return *this;
}

void Brain::setIdea(int index, std::string idea) {
	if (index < 0 || index >= 100)
		return;
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
	if (this->ideas[index].empty())
		return "";
	if (index < 0 || index >= 100)
		return "";
	return this->ideas[index];
}

