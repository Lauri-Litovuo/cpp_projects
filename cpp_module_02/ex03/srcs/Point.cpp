/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:58:32 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/10 11:43:59 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Point.hpp"

Point::Point( void ) : _x(0), _y(0){
}

Point::Point ( const float x, const float y ) : _x(x), _y(y) {
}

Point::~Point( void ){
	
}

Point::Point( const Point& src ) : _x(src._x), _y(src._y)
{
}

Point& Point::operator=( Point& rhs )
{
		return (rhs);
}

const Fixed&  Point::getX( void ) const
{
	return this->_x;
}
const Fixed&	Point::getY( void ) const
{
	return this->_y;
}