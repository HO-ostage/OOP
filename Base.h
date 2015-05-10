#pragma once

#include <string>

class Named
{
public:
	Named(std::string& name) : _name(name) {};
	
	std::string getName(void) const;
	void setName(std::string name);

private:
	std::string _name;
};

class Printable : virtual public Named
{
public:
	Printable(std::string& name) : Named(name) {};

	virtual std::string print() const;
};