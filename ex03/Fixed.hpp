/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:41:25 by cmartino          #+#    #+#             */
/*   Updated: 2024/02/20 11:50:13 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_fractBits = 8;
	
	public:
		Fixed();
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int					toInt(void) const;
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		static Fixed		min(Fixed& nb1,Fixed& nb2);
		static Fixed		max(Fixed& nb1,Fixed& nb2);
		static const Fixed	min(const Fixed& nb1,const Fixed& nb2);
		static const Fixed	max(const Fixed& nb1,const Fixed& nb2);

		bool	operator>(const Fixed& rhs) const;
		bool	operator<(const Fixed& rhs) const;
		bool	operator>=(const Fixed& rhs) const;
		bool	operator<=(const Fixed& rhs) const;
		bool	operator==(const Fixed& rhs) const;
		bool	operator!=(const Fixed& rhs) const;

		Fixed	operator+(const Fixed& rhs) const;
		Fixed	operator-(const Fixed& rhs) const;
		Fixed	operator*(const Fixed& rhs) const;
		Fixed	operator/(const Fixed& rhs) const;

		Fixed	operator++(int);
		Fixed	operator--(int);
		Fixed&	operator++(void);
		Fixed&	operator--(void);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
