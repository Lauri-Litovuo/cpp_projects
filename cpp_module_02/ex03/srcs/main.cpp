/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:48:46 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/11 11:13:44 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Fixed.hpp"
#include "../incl/Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(){
	Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    // Points inside the triangle
    Point inside1(5.0f, 5.0f);
    Point inside2(3.0f, 3.0f);
    Point inside3(4.9f, 4.9f);

    // Points outside the triangle
    Point outside1(15.0f, 5.0f);
    Point outside2(-5.0f, -5.0f);
    Point outside3(5.0f, 10.1f);
    Point outside4(10.1f, 0.0f);

    // Vertices of the triangle
    Point vertex1 = a;
    Point vertex2 = b;
    Point vertex3 = c;

    // Edges of the triangle
    Point edge1(5.0f, 0.0f);
    Point edge2(2.5f, 5.0f);
    Point edge3(7.5f, 5.0f);

    // Points on the extended lines of the triangle's edges
    Point extended1(15.0f, 0.0f);
    Point extended2(0.0f, 15.0f);
    Point extended3(10.0f, 15.0f);
    
    std::cout << "Inside1" << ": " << (bsp(a, b, c, inside1) ? "true" : "false") << std::endl;
    std::cout << "Inside2" << ": " << (bsp(a, b, c, inside2) ? "true" : "false") << std::endl;
    std::cout << "Inside3" << ": " << (bsp(a, b, c, inside3) ? "true" : "false") << std::endl;
    std::cout << "Outside1" << ": " << (bsp(a, b, c, outside1) ? "true" : "false") << std::endl;
    std::cout << "Outside2" << ": " << (bsp(a, b, c, outside2) ? "true" : "false") << std::endl;
    std::cout << "Outside3" << ": " << (bsp(a, b, c, outside3) ? "true" : "false") << std::endl;
    std::cout << "Outside4" << ": " << (bsp(a, b, c, outside4) ? "true" : "false") << std::endl;
    std::cout << "Vertex1" << ": " << (bsp(a, b, c, vertex1) ? "true" : "false") << std::endl;
    std::cout << "Vertex2" << ": " << (bsp(a, b, c, vertex2) ? "true" : "false") << std::endl;
    std::cout << "Vertex3" << ": " << (bsp(a, b, c, vertex3) ? "true" : "false") << std::endl;
    std::cout << "Edge1" << ": " << (bsp(a, b, c, edge1) ? "true" : "false") << std::endl;
    std::cout << "Edge2" << ": " << (bsp(a, b, c, edge2) ? "true" : "false") << std::endl;
    std::cout << "Edge3" << ": " << (bsp(a, b, c, edge3) ? "true" : "false") << std::endl;
    std::cout << "Extended1" << ": " << (bsp(a, b, c, extended1) ? "true" : "false") << std::endl;
    std::cout << "Extended2" << ": " << (bsp(a, b, c, extended2) ? "true" : "false") << std::endl;
    std::cout << "Extended3" << ": " << (bsp(a, b, c, extended3) ? "true" : "false") << std::endl;

    return 0;
}