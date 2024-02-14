/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:09:26 by cmartino          #+#    #+#             */
/*   Updated: 2024/02/14 13:47:52 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_fractBits;
	
	public:
		// Default constructor
			Fixed();
		
		//Copy constructor
			Fixed(const Fixed& other);

		//Copy assignment constructor	
			Fixed& operator=(const Fixed& other);

		//Destructor
			~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};

#endif