/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:49:17 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/05 16:13:35 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	return ;
}
Harl::~Harl()
{
	return ;
}
void	Harl::complain( std::string level)
{
	function_pointer fptr[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*fptr[i])();
			return ;
		}
	}
	return ;
}


void	Harl::debug( void )
{
	std::cout << "Debug messages contain contextual information. They are mostly used for problem diagnosis." << std::endl;
	std::cout << std::endl;
}
void	Harl::info( void )
{
	std::cout << "Info messages contain extensive information. They are helpful for tracing program execution in a production environment." << std::endl;
	std::cout << std::endl;
}
void	Harl::warning( void )
{
	std::cout << "Warning messages indicate a potential issue in the system." << std::endl;
	std::cout << std::endl;
}
void	Harl::error( void )
{
	std::cout << "These messages indicate an unrecoverable error has occurred. This is usually a critical issue that requires manual intervention." << std::endl;
	std::cout << std::endl;
}
