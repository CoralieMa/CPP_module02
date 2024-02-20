/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:41:36 by cmartino          #+#    #+#             */
/*   Updated: 2024/02/20 15:48:16 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*****    Constructor and destuctor    *****/

Point::Point():_x(0), _y(0){
	return ;
}

Point::Point(const Fixed x, const Fixed y): _x(x), _y(y){
	return;
}

Point::Point(const float x, const float y): _x(x), _y(y){
	return;
}

Point::Point(const Point& other){
	(Fixed) this->_x = (other.getX());
	(Fixed) this->_y = (other.getY());
	return ;
}

Point::~Point(void){
	return;
}

Point& Point::operator=(const Point& other){
	if (this != &other)
	{
		(Fixed) this->_x = other.getX();
		(Fixed) this->_y = other.getY();
	}
	return (*this);
}

Fixed	Point::getX(void) const{
	return (this->_x);
}

Fixed	Point::getY(void) const{
	return (this->_y);
}

bool	Point::operator==(const Point& rhs) const{
	if (this->_x == rhs.getX() && this->_y == rhs.getY())
		return (true);
	return (false);
}