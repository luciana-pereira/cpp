/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 06:47:04 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 07:02:01 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

/*
Essas funções e métodos definem a classe Point, que representa um ponto no plano 2D, e 
fornecem funcionalidades básicas para criar, copiar e acessar os membros de um objeto Point.
*/


/*
Construtor Padrão (Point::Point(void)): Inicializa um objeto Point com coordenadas x e y iguais a 0.
*/
Point::Point(void) : _x(0), _y(0) {}

/*
Construtor com Parâmetros (Point::Point(const float x, const float y)): Inicializa um objeto Point 
com as coordenadas x e y fornecidas como parâmetros.
*/
Point::Point(const float x, const float y) : _x(x), _y(y) {}

/*
Construtor de Cópia (Point::Point(const Point &src)): Cria um novo objeto Point a partir de outro objeto 
Point fornecido como argumento.
*/
Point::Point(const Point &src)
{
	*this = src;
}

/*
Destrutor (Point::~Point()): É responsável por destruir um objeto Point. No caso, como não há nada específico a ser 
liberado ou desalocado, ele está vazio.
*/
Point::~Point() {}

/*
Operador de Atribuição (Point &Point::operator=(const Point &rhs)): Sobrecarrega o operador de atribuição para permitir a 
cópia dos membros de um objeto Point para outro objeto Point.
*/
Point &Point::operator=(const Point &rhs)
{
	const_cast<Fixed&>(this->_x) = rhs._x;
	const_cast<Fixed&>(this->_y) = rhs._y;
	return (*this);
}

//Método getX: Retorna a coordenada x do objeto Point.
Fixed Point::getX(void) const
{
	return (this->_x);
}
 // Método getY: Retorna a coordenada y do objeto Point.
Fixed Point::getY(void) const
{
	return (this->_y);
}
