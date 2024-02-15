/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:33:05 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/14 06:09:13 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <iostream>

class	MateriaSource : public IMateriaSource
{
private:
	AMateria*	_learnedMaterias[4];
public:
	MateriaSource(void);
	~MateriaSource(void);
	MateriaSource(MateriaSource const &m);
	void	learnMateria(AMateria* m);
	AMateria*	createMateria(std::string const &type);
	MateriaSource&	operator=(MateriaSource const &m);
};

#endif
