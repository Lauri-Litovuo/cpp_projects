/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:53:13 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/11 13:07:56 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point {
	public:
		Point( void );
		Point( const float x, const float y );
		~Point( void );
		Point( const Point& src );
		Point& operator=( Point& rhs );

		const Fixed&  getX( void ) const;
		const Fixed&	getY( void ) const;

	private:
		const Fixed _x;
		const Fixed _y;
};

#endif