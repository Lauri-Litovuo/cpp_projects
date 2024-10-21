/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:03:15 by llitovuo          #+#    #+#             */
/*   Updated: 2024/10/21 20:10:54 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"
#include "Cat.hpp"
#include <sstream>
#include <cassert>
#define COUNT 4

void testAnimalArray() {
	const Animal* animalArray[COUNT];
	for (int i = 0; i < COUNT; i++) {
		if (i % 2 == 0)
			animalArray[i] = new Dog();
		else
			animalArray[i] = new Cat();
	}
	for (int i = 0; i < COUNT; i++) {
		animalArray[i]->makeSound();
	}
	for (int i = 0; i < COUNT; i++) {
		delete animalArray[i];
	}
}

void testAnimalArrayWithBrain() {
	const Animal* animalArray[COUNT];
	for (int i = 0; i < COUNT; i++) {
		if (i % 2 == 0)
			animalArray[i] = new Dog();
		else
			animalArray[i] = new Cat();
	}
	for (int i = 0; i < COUNT; i++) {
		animalArray[i]->makeSound();
	}
	for (int i = 0; i < COUNT; i++) {
		if (i % 2 == 0) {
			Dog *dog = (Dog *)animalArray[i];
			dog->setBrain(i, "Dog idea");
			std::cout << dog->getBrain(i) << std::endl;
		}
		else {
			Cat *cat = (Cat *)animalArray[i];
			cat->setBrain(i, "Cat idea");
			std::cout << cat->getBrain(i) << std::endl;
		}
	}
	for (int i = 0; i < COUNT; i++) {
		delete animalArray[i];
	}
}

void testSingleAnimals() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; // should not create a leak
	delete i;
}

void testAbstractMakeSound() {
	//The following is not compiling because of Animals' abstract
	// Animal *animal = new Animal();
	// animal->makeSound();
	// delete animal;

	//The following does
	Animal *dog = new Dog();
	dog->makeSound();
	delete dog;
	
}

int main() {
	testAnimalArray();
	std::cout << "\n\n---------------------\n" << std::endl;
	testAnimalArrayWithBrain();
	std::cout << "\n\n---------------------\n" << std::endl;
	testSingleAnimals(); //subject
	std::cout << "\n\n---------Seems to work as it did----------\n" << std::endl;
	testAbstractMakeSound();
	
	return 0;
}