/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:47:12 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/14 15:16:55 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

#include <string>
#include <iostream>

class	AMateria
{
protected:
	std::string _type;
public:
	AMateria(void);
	AMateria(AMateria const &m);
	AMateria(std::string const &type);
	virtual ~AMateria(void);
	std::string const &getType() const;
	virtual AMateria* clone() const = 0;
	virtual void	use(ICharacter& target);
	AMateria&	operator=(AMateria const &m);
};

#endif
