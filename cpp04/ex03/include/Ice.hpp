/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:44:14 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/14 06:27:27 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

#include <iostream>

class	Ice: public AMateria
{
public:
	Ice(void);
	~Ice(void);
	Ice(Ice const &m);
	AMateria* clone(void) const;
	void	use(ICharacter& target);
	Ice&	operator=(Ice const &m);
};

std::ostream& operator<<(std::ostream &stream, const Ice& m);

#endif
