/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:01:23 by lucperei          #+#    #+#             */
/*   Updated: 2024/05/14 05:03:49 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Este é o construtor padrão da classe Array. Ele cria um objeto Array vazio.
template <typename T>
Array<T>::Array(void) : _elements(NULL), _size(0) {}

// Este é o construtor de cópia da classe Array. Ele cria um novo objeto Array que é uma cópia exata de outro objeto Array passado como argumento.
template <typename T>
Array<T>::Array(const Array<T>& other) : _size(other._size) {
	_elements = new T[_size];
	for (unsigned int i = 0; i < _size; ++i) {
		_elements[i] = other._elements[i];
	}
}

/*
Este é um construtor que aceita um argumento n, que é o tamanho inicial do array. Ele aloca memória para o array com o tamanho especificado
*/
template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
	_elements = new T[_size];
}

/*
Este é o destrutor da classe Array. Ele é responsável por liberar a memória alocada para o array quando o objeto Array é destruído.
*/
template <typename T>
Array<T>::~Array(void) {
	delete[] _elements;
}

/*
Este é o operador de atribuição da classe Array. Ele permite que um objeto Array seja atribuído a outro objeto Array, 
fazendo uma cópia profunda dos elementos do array.
*/
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		delete[] _elements;
		_size = other.size_;
		_elements = new T[_size];
		for (unsigned int i = 0; i < _size; ++i) {
			_elements[i] = other._elements[i];
		}
	}
	return (*this);
}

/*
Este é o operador de acesso ao elemento do array. Ele retorna uma referência ao elemento no índice especificado, 
permitindo a leitura ou modificação do valor desse elemento.
*/
template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size) {
		throw std::exception();
	}
	return (_elements[index]);
}

// Este é o operador de acesso ao elemento do array constante. Ele permite a leitura do elemento no índice especificado, 
// mas não permite a modificação do valor desse elemento.
template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= _size) {
		throw std::exception();
	}
	return (_elements[index]);
}

// Este é um método constante que retorna o tamanho do array.
template <typename T>
unsigned int Array<T>::size(void) const {
	return (_size);
}
