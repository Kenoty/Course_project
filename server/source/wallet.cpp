#include "wallet.h"

void Wallet::setBalance(float value)
{
	this->balance = value;
}

float Wallet::getBalance() const
{
	return this->balance;
}
