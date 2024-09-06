/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:49:15 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/06 10:06:37 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# include <string>


class Harl {
	
	public:
		Harl();
		~Harl();
		void complain( std::string level);

	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

typedef void (Harl::*function_pointer)(void);

#endif