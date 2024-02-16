/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:05:09 by cmartino          #+#    #+#             */
/*   Updated: 2024/02/16 14:36:34 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _value(0){
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int nbr): _value(nbr << _fractBits){
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const float nbr): _value(roundf(nbr * (1 << this->_fractBits))){
	std::cout << "Float constructor called " << this->_value << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(other.getRawBits());
	return;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw){
	this->_value = raw;
	return;
}

float	Fixed::toFloat(void) const{
	 return (static_cast<float>(this->_value) / (1 << this->_fractBits));
}

int	Fixed::toInt(void) const{
	return (this->_value >> this->_fractBits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs){
	o << rhs.toFloat();
	return (o);
}
