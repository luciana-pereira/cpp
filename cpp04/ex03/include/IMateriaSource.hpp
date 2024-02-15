/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:35:12 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/13 04:35:38 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class	IMateriaSource
{
public:
	virtual ~IMateriaSource(void) {}
	virtual void learnMateria(AMateria* m) = 0;
	virtual AMateria* createMateria(std::string const &type) = 0;
};

#endif
