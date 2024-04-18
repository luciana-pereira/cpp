/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 06:41:19 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/11 06:45:06 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

/*
A função calcula o valor absoluto de um número fixo.
Ela verifica se x é menor que zero, pois se for, 
retorna -x para garantir que o valor absoluto seja sempre positivo, caso contrário, retorna x.
*/
static Fixed	abs(Fixed x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

/*
Calcula a área do triângulo formado pelos três pontos usando a fórmula da área de um triângulo 
com coordenadas cartesianas. Esta função estática recebe três pontos a, b e c como entrada, 
representando vértices de um triângulo.

getX e getY são métodos que fazem parte da classe Point e são usados para obter as coordenadas x e y de um ponto.
*/
static Fixed	area(Point const a, Point const b, Point const c)
{
	return (((a.getX() * (b.getY() - c.getY())) +
			(b.getX() * (c.getY() - a.getY())) +
			(c.getX() * (a.getY() - b.getY()))) /
			2);
}

/*
Esta função verifica se um ponto está dentro de um triângulo usando o método de Baricentro, 
Ela  recebe quatro pontos: a, b, c representando os vértices de um triângulo e point representando o ponto a ser verificado.
Calcula a área do triângulo formado pelos pontos a, b e c usando a função area.
Calcula as áreas dos três subtriângulos formados pelos pontos point, a, b; point, b, c; point, c, a usando a função area.
Calcula o valor absoluto de todas as áreas usando a função abs.
Retorna true se a soma das áreas dos subtriângulos for igual à área do triângulo original.
Caso contrário, retorna false.
*/
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed abcArea = abs(area(a, b, c));
	Fixed pabArea = abs(area(point, a, b));
	Fixed pbcArea = abs(area(point, b, c));
	Fixed pcaArea = abs(area(point, c, a));
	return (abcArea == pabArea + pbcArea + pcaArea);
}
