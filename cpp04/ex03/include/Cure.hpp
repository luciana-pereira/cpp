/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:41:20 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/14 22:29:08 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"


class	Cure: public AMateria
{
public:
	Cure();
	~Cure(void);
	Cure(Cure const &m);
	Cure(std::string const & type);
	AMateria* clone(void) const;
	void	use(ICharacter& target);
	Cure&	operator=(Cure const &m);
};

std::ostream&	operator<<(std::ostream &stream, Cure const &m);

#endif
