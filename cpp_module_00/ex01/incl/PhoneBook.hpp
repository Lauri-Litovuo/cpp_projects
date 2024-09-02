/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:32:13 by llitovuo          #+#    #+#             */
/*   Updated: 2024/08/29 14:36:26 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# define MAX_COUNT 8

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		bool	addContact(void);
		bool	searchContact(void);
		bool	deleteContact(void);
	
	private:
		Contact contacts[MAX_COUNT];
};

#endif
