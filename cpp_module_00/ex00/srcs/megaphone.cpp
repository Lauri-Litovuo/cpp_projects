/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:57:05 by llitovuo          #+#    #+#             */
/*   Updated: 2024/08/28 12:25:44 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>

int	main(int ac, char **av)
{
	size_t	i;
	int		j;
	char	ch;

	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	j = 0;
	while (++j < ac)
	{
		i = 0;
		while (i < strlen(av[j]))
		{
			ch = toupper(av[j][i]);
			std::cout << ch;
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}

