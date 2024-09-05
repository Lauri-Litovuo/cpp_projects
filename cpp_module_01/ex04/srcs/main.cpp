/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:42:46 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/05 14:38:36 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

std::string	replace_string(std::string &line, std::string &s1, std::string &s2)
{
	std::string newLine;
	size_t pos = 0;
	size_t found;


	while((found = line.find(s1, pos)) != std::string::npos)
	{
		newLine.append(line, pos, found - pos);
		newLine.append(s2);
		pos = found + s1.length();
	}
	
	newLine.append(line, pos, std::string::npos);
	return (newLine);
	
}

bool mySed(std::string &filename, std::string &s1, std::string &s2)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return (false);
	}
	std::string newFilename = filename + ".replace";
	std::ofstream newFile(newFilename);
	if (!newFile.is_open())
	{
		std::cout << "Error creating new file" << std::endl;
		return (false);
	}
	{
		std::string line;
		while (std::getline(file, line))
		{
			std::string newLine = replace_string(line, s1, s2);
			newFile << newLine << std::endl;
		}
	}
	file.close();
	newFile.close();
	return (true);
}

bool check_input(std::string &filename, std::string &s1)
{
	if (filename.empty() || s1.empty())
	{
		std::cout << "Filename or s1 cannot be empty" << std::endl;
		return (false);
	}
	std::filesystem::path path = filename;
	if (!std::filesystem::exists(path))
	{
		std::cout << "File does not exist" << std::endl;
		return (false);
	}
	if(!std::filesystem::is_regular_file(path))
	{
		std::cout << "File is something else than regular" << std::endl;
		return (false);
	}
	return (true);
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Exacly 3 arguments required: filename, s1:string to be replaced, s2:string to replace with" << std::endl;
		return (1);
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	
	if (!check_input(filename, s1))
		return (1);
	
	if (!mySed(filename, s1, s2))
		return (1);
	return (0);
}