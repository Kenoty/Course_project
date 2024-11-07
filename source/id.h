#pragma once

class Id
{
protected:
	int id = 0;
public:
	Id(int value = 0) : id(value) {};
	void set_id(int);
	int get_id() const;
};