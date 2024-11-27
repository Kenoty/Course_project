#include "wallet.h"

void Wallet::set_balance(float value)
{
	this->balance = value;
}

float Wallet::get_balance() const
{
	return this->balance;
}
