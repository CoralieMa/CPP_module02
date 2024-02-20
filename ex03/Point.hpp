/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:41:39 by cmartino          #+#    #+#             */
/*   Updated: 2024/02/20 15:26:16 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	POINT_HPP
# define POINT_HPP

# include <cmath>
# include <iostream>
# include "Fixed.hpp"

class Point
{	
	public:
		Point();
		Point(const float x, const float y);
		Point(const Fixed x, const Fixed y);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();

		Fixed	getX(void) const;
		Fixed	getY(void) const;

		bool	operator==(const Point& rhs) const;
	
	private:
		Fixed const	_x;
		Fixed const	_y;
};

bool isInTriangle(Point& a, Point& b, Point& c, Point& point);

#endif
