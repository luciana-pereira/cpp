/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:41:42 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/17 21:33:40 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class AForm;

class	Intern
{
public:
    Intern(void);
    Intern(const Intern &obj);
    ~Intern(void);
    Intern &operator=(const Intern &obj);
    AForm* makeForm(const std::string& request, const std::string& target);
};

#endif
