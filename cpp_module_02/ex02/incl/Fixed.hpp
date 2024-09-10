/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:52:45 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/10 09:18:24 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {
	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const & src);

		~Fixed(void);

		Fixed & operator=(Fixed const & rhs);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		bool operator>(Fixed const& rhs) const;
		bool operator<(Fixed const& rhs) const;
		bool operator>=(Fixed const& rhs) const;
		bool operator<=(Fixed const& rhs) const;
		bool operator==(Fixed const& rhs) const;
		bool operator!=(Fixed const& rhs) const;
		
		Fixed operator+(Fixed const& rhs) const;
		Fixed operator-(Fixed const& rhs) const;
		Fixed operator*(Fixed const& rhs) const;
		Fixed operator/(Fixed const& rhs) const;
		
		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed const& min(Fixed const& a, Fixed const& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static Fixed const& max(Fixed const& a, Fixed const& b);
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, Fixed const& rhs);

#endif