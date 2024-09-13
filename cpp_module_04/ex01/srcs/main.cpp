/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:03:15 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/13 13:38:22 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "../incl/Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "../incl/WrongDog.hpp"
#include "WrongCat.hpp"
#include <sstream>
#include <cassert>


int main() {
	{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	assert(j->getType() == "Dog");
	assert(i->getType() == "Cat");
	assert(meta->getType() == "Animal");
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;
	}
	std::cout << "---------------------" << std::endl;
	{
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* j = new WrongDog();
	const WrongAnimal* i = new WrongCat();
	
	assert(j->getType() == "WrongDog");
	assert(i->getType() == "WrongCat");
	assert(meta->getType() == "WrongAnimal");
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;
	}
	
	return 0;
}