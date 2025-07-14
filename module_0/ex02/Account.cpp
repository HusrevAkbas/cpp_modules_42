/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:40:03 by husrevakbas       #+#    #+#             */
/*   Updated: 2025/07/15 01:28:35 by husrevakbas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "iostream"
#include "ctime"
#include "iomanip"

/*
	'const' after function name:
	you cannot change variables anymore via this keyword in the function
	
	static members of a class shared by all instances.
	any change applies for all instances immediately

*/

Account::Account () {};

Account::Account(int initial_deposit)
{	
	this->_amount = initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;
	Account::_totalAmount += this->_amount;
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";created" << std::endl;
}

Account::~Account () {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";closed" << std::endl;
};

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{	return (Account::_nbAccounts);		}

int	Account::getTotalAmount( void )
{	return (Account::_totalAmount);		}

int	Account::getNbDeposits( void )
{	return (Account::_totalNbDeposits);	}

int	Account::getNbWithdrawals( void )
{	return (Account::_totalNbWithdrawals);	}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts
	<< ";total:" << Account::_totalAmount
	<< ";deposits:" << Account::_totalNbDeposits
	<< ";withdrawals:" << Account::_totalNbWithdrawals
	<< std::endl;
}

void	Account::makeDeposit(int deposit)
{	
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";p_amount:" << this->_amount
	<< ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << ";amount:" << this->_amount
	<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";p_amount:" << this->_amount;
	if (withrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withrawal;
	Account::_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withrawal
	<< ";amount:" << this->_amount
	<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}
/*
	'const' after function name:
	you cannot change variables anymore via this keyword in the function
*/
int	Account::checkAmount( void ) const
{	
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals
	<< std::endl;
}

void	Account::_displayTimestamp( void )
{	
	time_t		timest;
	struct tm	datetime;
	
	time(&timest);
	datetime = *localtime(&timest);
/*
	// JUST FOR TEST - print into file, compare with diff command
	datetime.tm_year = 92;
	datetime.tm_mon = 1;
	datetime.tm_mday = 4;
	datetime.tm_hour = 9;
	datetime.tm_min = 15;
	datetime.tm_sec = 32;
	// JUST FOR TEST
*/
	std::cout << "[" << 1900 + datetime.tm_year
	<< std::setw(2) << std::setfill('0') << datetime.tm_mon
	<< std::setw(2) << std::setfill('0') << datetime.tm_mday
	<< "_" << std::setw(2) << std::setfill('0') << datetime.tm_hour
	<< std::setw(2) << std::setfill('0') << datetime.tm_min
	<< std::setw(2) << std::setfill('0') << datetime.tm_sec
	<< "] ";
}