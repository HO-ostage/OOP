#pragma once

#include <string>

class Named
{
public:
	Named(const char * name) : _name(name) {};
	Named() {};
protected:
	std::string _name;
};

class Printable : virtual public Named
{
public:
	Printable(const char * name) { _name = name; };
	std::string getName(void) const;
};