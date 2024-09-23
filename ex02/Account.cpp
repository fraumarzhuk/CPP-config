#include "Account.hpp"

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	_totalAmount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_displayTimestamp();
	std::cout << "index:" << RED << _accountIndex << RESET << ";";
	std::cout << "amount:" << RED << _amount << RESET << ";";
	std::cout << "created" << std::endl;
}
Account::Account(void)
{
	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << RED << _accountIndex << RESET << ";";
	std::cout << "amount:" << RED << _amount << RESET << ";";
	std::cout << "closed" << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << RED << _accountIndex << RESET << ";";
	std::cout << "amount:" << RED << _amount << RESET << ";";
	std::cout << "deposits:" << RED << _amount << RESET << ";";
	std::cout << "withdrawals:" << RED << _amount << RESET << std::endl;
}

int	 Account::getNbAccounts( void )
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

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:"<< RED << _nbAccounts << RESET << ";";
	std::cout << "total:"<< RED << _totalAmount << RESET << ";";
	std::cout << "deposits:"<< RED << _totalNbDeposits << RESET << ";";
	std::cout << "withdrawals:"<< RED << _totalNbWithdrawals << RESET << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:"<< RED << this->_accountIndex << RESET << ";";
	std::cout << "p_amount:"<< RED << _totalAmount << RESET << ";";
	std::cout << "deposit:"<< RED << deposit << RESET << ";";
	this->_nbDeposits += 1;
	this->_totalAmount += deposit;
	std::cout << "amount:"<< RED << _totalAmount << RESET << ";";
	std::cout << "nb_deposits:"<< RED << this->_nbDeposits<< RESET << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:"<< RED << this->_accountIndex << RESET << ";";
	std::cout << "p_amount:"<< RED << _totalAmount << RESET << ";";
	if (withdrawal <= _amount)
	{
		std::cout << "withdrawal:"<< RED << withdrawal << RESET << ";";
		this->_totalNbWithdrawals += 1;
		this->_totalAmount -= withdrawal;
		std::cout << "amount:"<< RED << _totalAmount << RESET << ";";
		std::cout << "nb_withdrawals:"<< RED << this->_nbWithdrawals<< RESET << std::endl;;
		return (true);
	}
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
}
void Account::_displayTimestamp(void)
{
	time_t current_time = time(NULL);
	struct tm *local_time = localtime(&current_time);
	std::cout << '[' << local_time->tm_year + 1900 << local_time->tm_mon << local_time->tm_mday
	<< "_" << local_time->tm_hour << local_time->tm_min << local_time->tm_sec << "] ";
}