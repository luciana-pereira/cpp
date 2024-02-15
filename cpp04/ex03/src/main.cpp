/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:33:24 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/15 01:38:08 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"
#include "../include/MateriaSource.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"

int	main(void)
{
	std::cout << "===================== Materia Source Test ======================" << std::endl;
	IMateriaSource* src = new MateriaSource();
	std::cout << "====================== Learn Materia Test ======================" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << "======================== Character Test ========================" << std::endl;
	ICharacter* me = new Character("me");
	std::cout << "====================== Create Materia Test =====================" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp;
	std::cout << "====================== Character Bob Test ======================" << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	std::cout << "================== Deep Copy Character Test ====================" << std::endl;
	Character* test = new Character("test");
	tmp = src->createMateria("ice");
	test->equip(tmp);
	tmp = src->createMateria("cure");
	test->equip(tmp);
	Character* test_copy = new Character(*test);
	std::cout << "================================================================" << std::endl;
	test->use(0, *bob);
	test->use(1, *bob);
	test->use(2, *bob);
	test->use(3, *bob);
	std::cout << "================================================================" << std::endl;
	AMateria* tmp2;
	tmp2 = test_copy->getMateria(1);
	test_copy->unequip(1);
	delete tmp2;
	tmp = src->createMateria("ice");
	test_copy->equip(tmp);
	tmp = src->createMateria("ice");
	test_copy->equip(tmp);
	std::cout << "============================= Test =============================" << std::endl;
	test->use(0, *bob);
	test->use(1, *bob);
	test->use(2, *bob);
	test->use(3, *bob);
	std::cout << "=========================== Test Copy ==========================" << std::endl;
	test_copy->use(0, *bob);
	test_copy->use(1, *bob);
	test_copy->use(2, *bob);
	test_copy->use(3, *bob);
	std::cout << "================================================================" << std::endl;
	*test_copy = *test;
	tmp = src->createMateria("cure");
	test_copy->equip(tmp);
	std::cout << "============================= Test =============================" << std::endl;
	test->use(0, *bob);
	test->use(1, *bob);
	test->use(2, *bob);
	test->use(3, *bob);
	std::cout << "=========================== Test Copy ==========================" << std::endl;
	test_copy->use(0, *bob);
	test_copy->use(1, *bob);
	test_copy->use(2, *bob);
	test_copy->use(3, *bob);
	std::cout << "================================================================" << std::endl;
	std::cout << std::endl;
	std::cout << "========================= Unequip Test =========================" << std::endl;
	test->use(1, *test_copy);
	tmp2 = test->getMateria(1);
	test->unequip(1);
	delete tmp2;
	test->use(1, *test_copy);
	test->unequip(-4);
	test->unequip(42);
	test->unequip(1);
	std::cout << std::endl;
	std::cout << "======================== Delete Test ===========================" << std::endl;
	delete test_copy;
	delete test;
	delete bob;
	delete me;
	delete src;
	return (0);
}
