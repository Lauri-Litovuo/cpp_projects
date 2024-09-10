/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:08:54 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/10 15:12:54 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Point.hpp"
#include <iostream>
#include <cmath>


/*
Calculating the area of a triangle using the shoestring formula:
		|xp1(yp2 - yp3) + xp2(yp3 - yp1) + xp3(yp1 - yp2)|
Area = ----------------------------------------------------
								2
*/

static float calculateArea(Point const p1, Point const p2, Point const p3){
	float area;

	area = std::abs( (p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())) \
			+ (p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())) \
			+ (p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) ) \
			/ 2;
	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float area, p1, p2 ,p3;

	area = calculateArea(a, b, c);
	p1 = calculateArea(point, a, b);
	p2 = calculateArea(point, b, c);
	p3 = calculateArea(point, c, a);
	
	if ((point.getX().toFloat() == a.getX().toFloat() && point.getY().toFloat() == a.getY().toFloat()) ||
        (point.getX().toFloat() == b.getX().toFloat() && point.getY().toFloat() == b.getY().toFloat()) ||
        (point.getX().toFloat() == c.getX().toFloat() && point.getY().toFloat() == c.getY().toFloat()))
        return false;
	
	else if (p1 == 0 || p2 == 0 || p3 == 0)
		return false;
	
	else if (area == p1 + p2 + p3)
		return true;

	else
		return false;
}