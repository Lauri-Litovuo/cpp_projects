/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:03:15 by llitovuo          #+#    #+#             */
/*   Updated: 2024/10/23 10:06:45 by llitovuo         ###   ########.fr       */
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

void testBrainCopies() {
	Dog *dog = new Dog();

	dog->setBrain(0, "first dog idea");
	dog->setBrain(1, "second dog idea");

	std::cout << "Setting ideas... the dog has now ideas :" << std::endl;
	std::cout << dog->getBrain(0) << "\n" << dog->getBrain(1) << std::endl;
	Dog *dog2 = new Dog(*dog);

	std::cout << "the dog2 has now same ideas :" << std::endl;
	std::cout << dog2->getBrain(0) << "\n" << dog2->getBrain(1) << std::endl;

	std::cout << "\nChanging dog's first idea" << std::endl;
	dog->setBrain(0, "changed idea");

	std::cout << "Doggos ideas are now different, thus have their own brains" << std::endl;
	std::cout << "\nDog:" << std::endl;
	std::cout << dog->getBrain(0) << "\n" << dog->getBrain(1) << std::endl;

	std::cout << "Dog2:" << std::endl;
	std::cout << dog2->getBrain(0) << "\n" << dog2->getBrain(1) << std::endl;

	delete dog;
	delete dog2;

}

void testSingleAnimals() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; // should not create a leak
	delete i;
}

int main() {
	testAnimalArray();
	std::cout << "\n\n---------------------\n" << std::endl;
	testBrainCopies();
	std::cout << "\n\n---------------------\n" << std::endl;
	testSingleAnimals(); //subject
	return 0;
}
