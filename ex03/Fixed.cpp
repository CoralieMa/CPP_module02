/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:41:21 by cmartino          #+#    #+#             */
/*   Updated: 2024/02/20 14:51:26 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*****    Constructor and destuctor    *****/

Fixed::Fixed(): _value(0){
	return ;
}

Fixed::Fixed(const int nbr): _value(nbr << _fractBits){
	return ;
}

Fixed::Fixed(const float nbr): _value(roundf(nbr * (1 << this->_fractBits))){
	return ;
}

Fixed::Fixed(const Fixed& other){
	this->setRawBits(other.getRawBits());
	return;
}

Fixed::~Fixed(void){
	return;
}

Fixed& Fixed::operator=(const Fixed& other){
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

/*****    Usefull functions    *****/

int	Fixed::getRawBits(void) const{
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
/*****    Comparison operators    *****/

bool	Fixed::operator>(const Fixed& rhs) const{
	if (this->getRawBits() > rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& rhs) const{
	if (this->getRawBits() < rhs.getRawBits())
		return (true);
	return (false);
}
bool	Fixed::operator>=(const Fixed& rhs) const{
	if (this->getRawBits() >= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& rhs) const{
	if (this->getRawBits() <= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& rhs) const{
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& rhs) const{
	if (this->getRawBits() != rhs.getRawBits())
		return (true);
	return (false);
}

/*****    Arithmetic operators    *****/

Fixed	Fixed::operator+(const Fixed& rhs) const{
	Fixed	newFixedPoint(this->toFloat() + rhs.toFloat());

	return (newFixedPoint);
}
Fixed	Fixed::operator-(const Fixed& rhs) const{
	Fixed	newFixedPoint(this->toFloat() - rhs.toFloat());

	return (newFixedPoint);
}
Fixed	Fixed::operator*(const Fixed& rhs) const{
	Fixed	newFixedPoint(this->toFloat() * rhs.toFloat());

	return (newFixedPoint);
}
Fixed	Fixed::operator/(const Fixed& rhs) const{
	Fixed	newFixedPoint(this->toFloat() / rhs.toFloat());

	return (newFixedPoint);
}

/*****    Increment and decrement operators    *****/

Fixed	Fixed::operator++(int){
	Fixed	tempFixedPoint(*this);

	this->_value++;
	return (tempFixedPoint);
}

Fixed	Fixed::operator--(int){
	Fixed	tempFixedPoint(*this);

	this->_value--;
	return (tempFixedPoint);
}

Fixed&	Fixed::operator++(void){
	this->_value++;
	return (*this);
}

Fixed&	Fixed::operator--(void){
	this->_value--;
	return (*this);
}

/*****    Min and max    *****/

Fixed	Fixed::min(Fixed& nb1,Fixed& nb2){
	if (nb1.getRawBits() > nb2.getRawBits())
		return (nb2);
	return (nb1);
}
Fixed	Fixed::max(Fixed& nb1,Fixed& nb2){
	if (nb1.getRawBits() > nb2.getRawBits())
		return (nb1);
	return (nb2);
}

const Fixed	Fixed::min(const Fixed& nb1,const Fixed& nb2){
	if (nb1.getRawBits() > nb2.getRawBits())
		return (nb2);
	return (nb1);
}

const Fixed	Fixed::max(const Fixed& nb1,const Fixed& nb2){
	if (nb1.getRawBits() > nb2.getRawBits())
		return (nb1);
	return (nb2);
}

/*****    Overload << operator    *****/

std::ostream & operator<<(std::ostream & o, Fixed const & rhs){
	o << rhs.toFloat();
	return (o);
}
