#pragma once

class Wallet
{
	float balance;
public:
	Wallet(float value = 0) : balance(value) {};
    void setBalance(float value);
    float getBalance() const;
};
