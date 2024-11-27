#pragma once

class Wallet
{
	float balance;
public:
	Wallet(float value = 0) : balance(value) {};
	void set_balance(float value);
	float get_balance() const;
};