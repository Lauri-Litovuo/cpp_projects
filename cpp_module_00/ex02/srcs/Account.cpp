/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:09:37 by llitovuo          #+#    #+#             */
/*   Updated: 2024/09/03 19:33:43 by llitovuo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Account::Account( void )
// {
// 	_displayTimestamp();
// 	this->_accountIndex = _nbAccounts;
// 	std::cout << "index:" << this->_accountIndex;
// 	this->_nbAccounts++;
// 	this->_amount = 0;
// 	std::cout << ";	amount:" << this->_amount;
// 	this->_nbDeposits = 0;
// 	this->_nbWithdrawals = 0;
// 	std::cout << ";	created" << std::endl;
// 	return ;
// }

Account::Account( int initial_deposit )
{
	
	_displayTimestamp();
	this->_accountIndex = this->_nbAccounts;
	std::cout << "index:" << this->_accountIndex;
	this->_nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_amount += initial_deposit;
	_totalAmount += initial_deposit;
	std::cout << "; amount:" << this->_amount;
	this->_nbWithdrawals = 0;
	std::cout << "; created" << std::endl;
	return ;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << "; amount:" << this->_amount;
	std::cout << "; closed" << std::endl;
	return ;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << "; total:" << getTotalAmount();
	std::cout << "; deposits:" << getNbDeposits();
	std::cout << "; withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
	return ;
}

void	Account::makeDeposit( int deposit )
{
	if (deposit < 0)
	{
		std::cout << "Invalid deposit amount" << std::endl;
		return ;
	}
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << "; p_amaunt:" << this->_amount;
	std::cout << "; deposit:" << deposit;
	this->_amount += deposit;
	std::cout << "; amaunt:" << this->_amount;
	this->_nbDeposits++;
	std::cout << "; nb_deposits:" << this->_nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex;
	std::cout << "; p_amaunt:" << this->_amount;
	if (withdrawal < 0 || checkAmount() < withdrawal)
	{
		std::cout << "; withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "; withdrawal:" << withdrawal;
	this->_amount -= withdrawal;
	std::cout << "; amaunt:" << this->_amount;
	this->_nbWithdrawals++;
	std::cout << "; nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << "; amount:" << this->_amount;
	std::cout << "; deposits:" << this->_nbDeposits;
	std::cout << "; withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}

//private

//showing the current time in the format [YYYYMMDD_HHMMSS]
void	Account::_displayTimestamp( void )
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	std::cout << "[" << now->tm_year + 1900;
	if (now->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << now->tm_mon + 1;
	if (now->tm_mday < 10)
		std::cout << "0";
	std::cout << now->tm_mday << "_";
	if (now->tm_hour < 10)
		std::cout << "0";
	std::cout << now->tm_hour;
	if (now->tm_min < 10)
		std::cout << "0";
	std::cout << now->tm_min;
	if (now->tm_sec < 10)
		std::cout << "0";
	std::cout << now->tm_sec << "] ";
}