/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:57:49 by lucperei          #+#    #+#             */
/*   Updated: 2024/03/05 00:53:23 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template <class T>
class Array {
private:
	T*           _elements; // ponteiro para armazenar os elementos do array, T de qual quer tipo
	unsigned int _size;     // armazenar o tamanho do array
public:
	Array(void);: Este é o construtor padrão da classe Array. Ele cria um objeto Array vazio.
~Array(void);: Este é o destrutor da classe Array. Ele é responsável por liberar a memória alocada para o array quando o objeto Array é destruído.
Array(unsigned int n);: Este é um construtor que aceita um argumento n, que é o tamanho inicial do array. Ele aloca memória para o array com o tamanho especificado.

Array(const Array<T>& other);: Este é o construtor de cópia da classe Array. Ele cria um novo objeto Array que é uma cópia exata de outro objeto Array passado como argumento.

Array<T>& operator=(const Array<T>& other);: Este é o operador de atribuição da classe Array. Ele permite que um objeto Array seja atribuído a outro objeto Array, fazendo uma cópia profunda dos elementos do array.

T& operator[](unsigned int index);: Este é o operador de acesso ao elemento do array. Ele retorna uma referência ao elemento no índice especificado, permitindo a leitura ou modificação do valor desse elemento.

const T& operator[](unsigned int index) const;: Este é o operador de acesso ao elemento do array constante. Ele permite a leitura do elemento no índice especificado, mas não permite a modificação do valor desse elemento.

unsigned int size() const;: Este é um método constante que retorna o tamanho do array.
};

#include "./Array.tpp"

/*
Este include esta no final, é uma convenção comum em C++ para separar a implementação dos modelos (templates) 
da declaração das classes e funções no cabeçalho.
*/

#endif
