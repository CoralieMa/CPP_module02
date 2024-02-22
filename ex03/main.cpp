/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:41:30 by cmartino          #+#    #+#             */
/*   Updated: 2024/02/22 11:18:18 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void	printResult(bool result, Point const &p)
{
	std::cout << "Point (" << p.getX() << "," << p.getY() << ") is ";
	if (result)
		std::cout << "in the triangle" << std::endl;
	else
		std::cout << "not the triangle" << std::endl;

	return;
}

int main(void)
{
	Point	a(1.8f, 8.9f), b(3, 4.8f), c(3, 10), p(2.9f, 7);

	printResult(bsp(a, b, c, p), p);
	printResult(bsp(p, a, b, c), c);
	printResult(bsp(a, b, c, b), b);
	printResult(bsp(a, a, a, a), a);
	
	return (0);
}

// https://planetcalc.com/8108/