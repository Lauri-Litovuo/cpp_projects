/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:48:46 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/10 15:13:30 by llitovuo         ###   ########.fr       */
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

    auto printResult = [](const char* description, bool result) {
        std::cout << description << ": " << (result ? "true" : "false") << std::endl;
    };

    printResult("Inside1", bsp(a, b, c, inside1));
    printResult("Inside2", bsp(a, b, c, inside2));
    printResult("Inside3", bsp(a, b, c, inside3));
    printResult("Outside1", bsp(a, b, c, outside1));
    printResult("Outside2", bsp(a, b, c, outside2));
    printResult("Outside3", bsp(a, b, c, outside3));
    printResult("Outside4", bsp(a, b, c, outside4));
    printResult("Vertex1", bsp(a, b, c, vertex1));
    printResult("Vertex2", bsp(a, b, c, vertex2));
    printResult("Vertex3", bsp(a, b, c, vertex3));
    printResult("Edge1", bsp(a, b, c, edge1));
    printResult("Edge2", bsp(a, b, c, edge2));
    printResult("Edge3", bsp(a, b, c, edge3));
    printResult("Extended1", bsp(a, b, c, extended1));
    printResult("Extended2", bsp(a, b, c, extended2));
    printResult("Extended3", bsp(a, b, c, extended3));

    return 0;
}