/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:32:13 by llitovuo          #+#    #+#             */
/*   Updated: 2024/08/29 12:48:44 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class Phonebook
{
	#define MAX_COUNT 8

	private:

		int		Counter;
		Contact phoneBook[MAX_COUNT];

	public:

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
