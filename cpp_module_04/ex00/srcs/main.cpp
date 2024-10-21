/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:03:15 by llitovuo          #+#    #+#             */
/*   Updated: 2024/10/21 17:00:16 by llitovuo         ###   ########.fr       */
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
	std::cout << "Assertion passed: j->getType() == " << j->getType() << std::endl;
	assert(i->getType() == "Cat");
	std::cout << "Assertion passed: i->getType() == " << i->getType() << std::endl;
	assert(meta->getType() == "Animal");
	std::cout << "Assertion passed: meta->getType() == " << meta->getType() << std::endl;
	
	std::cout << "\n\nwhat does the cat say?" << std::endl;
	i->makeSound();
	std::cout << "what does the dog say?" << std::endl;
	j->makeSound();
	std::cout << "what does the animal say?" << std::endl;
	meta->makeSound();
	
	std::cout << "\n\ndeleting meta, j, i" << std::endl;
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