/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 02:22:26 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/13 02:23:01 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class	AAnimal
{
protected:
	std::string _type;
public:
	AAnimal(void);
	AAnimal(std::string type);
	AAnimal(const AAnimal &other);
	AAnimal &operator=(const AAnimal &other);
	virtual ~AAnimal(void);
	virtual void makeSound(void) const;
	std::string getType(void) const;
};

std::ostream &operator<<(std::ostream &stream, const AAnimal &other);

#endif
