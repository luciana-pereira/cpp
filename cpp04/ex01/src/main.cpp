/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:37:37 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/13 00:27:56 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Brain.hpp"

int	main(void)
{
	std::cout << "============================= Type and Sound Test =============================" << std::endl;

	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl;
    std::cout << "Animal type: " << animal->getType() << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;
	std::cout << std::endl;
	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	
    std::cout << "============================= End of Type and Sound Test =====================" << std::endl;
	
	delete animal;
	animal = NULL;
	delete dog;
	dog = NULL;
	delete cat;
	cat = NULL;
	
	std::cout << "============================= WrongAnimal Test ==============================" << std::endl;
	
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << std::endl;
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
    std::cout << "WrongAnimal type: " << wrongAnimal->getType() << std::endl;
	std::cout << std::endl;
	wrongCat->makeSound(); 
	wrongAnimal->makeSound();
	
    std::cout << "============================= End of WrongAnimal Test ========================" << std::endl;
	
	delete wrongAnimal;
	wrongAnimal = NULL;
	delete wrongCat;
	wrongCat = NULL;

	std::cout << "============================= Memory Leak Check ===============================" << std::endl;
	// Additional tests to check for memory leaks
    {
        const int animalCount = 6;
        Animal* animalArray[animalCount];

        // Create an array of Animal objects
        for (int i = 0; i < animalCount / 2; ++i)
            animalArray[i] = new Dog();
        for (int i = animalCount / 2; i < animalCount; ++i)
            animalArray[i] = new Cat();
        // Delete the array of Animal objects
        for (int i = 0; i < animalCount; ++i)
            delete animalArray[i];
        // Check for memory leaks
        for (int i = 0; i < animalCount; ++i)
            animalArray[i] = new Dog();  // Create objects again
        // Delete the array of Animal objects
        for (int i = 0; i < animalCount; ++i)
            delete animalArray[i];
    }
	
	return (0);
}
