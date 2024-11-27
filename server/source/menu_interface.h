#pragma once

class IMenu
{
public:
	virtual void output_menu() = 0;
	virtual void choose_option() = 0;
	void routine();
};