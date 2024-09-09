/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:52:45 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/09 11:26:21 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

//class in orthodox canonical form

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed & operator=(Fixed const & rhs);

		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;
};

#endif