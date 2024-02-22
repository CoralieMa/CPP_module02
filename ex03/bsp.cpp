/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:41:28 by cmartino          #+#    #+#             */
/*   Updated: 2024/02/22 11:18:51 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	max(Fixed const& nb1, Fixed const& nb2, Fixed const& nb3){
	Fixed max(nb1);

	if (nb1 < nb2)
		max = nb2;
	if (max < nb3)
		max = nb3;
	return (max);
}

Fixed	min(Fixed const& nb1, Fixed const& nb2, Fixed const& nb3){
	Fixed min(nb1);

	if (nb1 > nb2)
		min = nb2;
	if (min > nb3)
		min = nb3;	
	return (min);
}

bool	isTriangle(Point const& nb1, Point const& nb2, Point const& nb3){
	Fixed a, b;

	if (nb1 == nb2 || nb1 == nb3 || nb2 == nb3)
		return (false);
	// equation of the line nb1nb2 : y = ax + b
	a = (nb2.getY() - nb1.getY()) / (nb2.getX() - nb1.getX());
	b = (nb1.getY()) - (a * nb1.getX());

	// Checking if nb3 is on the line nb1nb2
	if (nb3.getY() - (a * nb3.getX()) == b)
		return (false); 

	return (true);
}

bool	minMaxVerification(Point const& a, Point const& b, Point const& c, Point const& point){
	Fixed	xMin(min(a.getX(), b.getX(), c.getX()));
	Fixed	xMax(max(a.getX(), b.getX(), c.getX()));
	Fixed	yMin(min(a.getY(), b.getY(), c.getY()));
	Fixed	yMax(max(a.getY(), b.getY(), c.getY()));

	if (point.getX() <= xMin || point.getX() >= xMax || point.getY() <= yMin || point.getY() >= yMax)
		return (false);
	return (true);
}

Fixed	determinant(Point const& point, Point const& vertex1, Point const& vertex2){
	Fixed	vector1x(point.getX() - vertex1.getX());
	Fixed	vector1y(point.getY() - vertex1.getY());
	Fixed	vector2x(point.getX() - vertex2.getX());
	Fixed	vector2y(point.getY() - vertex2.getY());

	return ((vector1x * vector2y) - (vector2x * vector1y));
}

bool	determinantVerification(Point const& a, Point const& b, Point const& c, Point const& point){
	Fixed	detA(determinant(point, b, c));
	Fixed	detB(determinant(point, c, a));
	Fixed	detC(determinant(point, a, b));

	if (((detA * detB) > 0) && ((detB * detC) > 0))
		return (true);
	return (false);
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
	if (! isTriangle(a, b, c))
		return (false);
	if (! minMaxVerification(a, b, c, point))
		return (false);
	if (! determinantVerification(a, b, c, point))
		return (false);
	return (true);
}
