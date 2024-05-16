/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:22:07 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/16 20:58:17 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <vector>
#include <iterator>
#include <iostream>

// Declaração da classe MutantStack que herda de std::stack
template <typename T>
class MutantStack : public std::stack<T>
{
public:
    // Declaração de tipos para iteradores
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    // Declaração de construtores e destrutor
    MutantStack(void);
    MutantStack(const MutantStack &other);
    ~MutantStack(void);

    // Sobrecarga do operador de atribuição
    MutantStack &operator=(const MutantStack &other);

    // Métodos para obtenção de iteradores de início e fim
    iterator begin(void);
    iterator end(void);

    // Métodos para obtenção de iteradores constantes de início e fim
    const_iterator cbegin(void) const;
    const_iterator cend(void) const;

    // Métodos para obtenção de iteradores de início e fim reversos
    reverse_iterator rbegin(void);
    reverse_iterator rend(void);

    // Métodos para obtenção de iteradores constantes de início e fim reversos
    const_reverse_iterator crbegin(void) const;
    const_reverse_iterator crend(void) const;
};

#include "MutantStack.tpp" // Inclusão do arquivo de implementação

#endif
