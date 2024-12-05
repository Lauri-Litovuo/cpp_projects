/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:15:47 by llitovuo          #+#    #+#             */
/*   Updated: 2024/12/05 11:02:26 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}