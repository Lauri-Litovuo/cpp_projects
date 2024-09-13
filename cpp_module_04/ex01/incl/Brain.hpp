/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:39:12 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/13 14:47:52 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>

class Brain{
	public:
		Brain( void );
		~Brain( void );
		Brain( Brain const& src );
		Brain& operator= (Brain const& rhs);
		void setIdea( std::string idea, int index );
		std::string getIdea(int index) const;

	private:
		std::string ideas[100];
};

#endif