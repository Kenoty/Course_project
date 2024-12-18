#pragma once

class IMenu
{
public:
	virtual void outputMenu() = 0;
	virtual void chooseOption() = 0;
	void routine();
};