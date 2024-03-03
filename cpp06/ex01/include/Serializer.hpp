/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 03:25:42 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/26 03:26:42 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

class	Serializer {
public:
    Serializer() = delete;
    static unsigned int	serialize(Data* ptr);
    static Data*	deserialize(unsigned int raw);
};

#endif 
