#pragma once

class Id
{
protected:
	int id;
public:
	Id(int value = 0) : id(value) {};
    void setId(int);
    int getId() const;
};
