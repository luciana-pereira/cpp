/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:37:37 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/12 17:50:37 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

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
	
	return (0);
}
