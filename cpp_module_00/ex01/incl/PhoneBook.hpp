/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:32:13 by llitovuo          #+#    #+#             */
/*   Updated: 2024/08/29 12:57:15 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>

class Phonebook
{
	#define MAX_COUNT 8

	private:

		int		Counter;
		Contact phoneBook[MAX_COUNT];

	public:
		Phonebook(){
			std::cout << "Write ADD to add, SEARCH to search or EXIT to exit";
		}
	
		bool	addContact(void);
		bool	SearchContact(void);
		bool	DeleteContact(void);
		void	getFirstName();
		void	getLastName();
		void	getNickName();
		void	getPhoneNumber();
		void	getSecret();
};

#endif
