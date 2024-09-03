/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:32:13 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/03 16:02:30 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
# include <string>

# define MAX_COUNT 8
# define MAX_WIDTH 10


class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		bool	addContact(void);
		bool	searchContact(void);
	
	private:
		Contact _contacts[MAX_COUNT];
		int		_contactPosition;
};

#endif
