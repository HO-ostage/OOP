#pragma once

#include "Base.h"
#include "XList.cpp"
#include <iostream>
#include <sstream>

class Shape : virtual public Named
{
public:
	static unsigned int getCount(void)
	{
		return count;
	}
	
	~Shape()
	{
		--count;
	}

private:
	static unsigned int count;
};

class Point : public Printable, public Shape
{
public:
	Point(int x, int y) : _x(x), _y(y), Printable(std::string("Point")) { };
	
	std::string print() const
	{

		std::stringstream tmp;
		tmp << this->getName() << " X=" << _x << " Y=" << _y;
		
		return tmp.str();
	}

	int getX() const 
	{
		return _x;
	}

	int getY() const
	{
		return _y;
	}

	friend std::ostream& operator<< (std::ostream& ioStream, const Point& point);

private:
	int _x, _y;
};

class Circle : public Shape, public Printable
{
public:
	Circle(int x, int y, unsigned int r) : _center(x, y) , _r(r), Printable("Circle") { };
	Circle(Point center, unsigned int r) : _center(center), _r(r), Printable("Circle") { };

	std::string print() const
	{
		std::stringstream tmp;
		tmp << this->getName() << " X=" << _center.getX() << " Y=" << _center.getY() << " R=" << _r;

		return std::string(tmp.str());
	}

	friend std::ostream& operator<< (std::ostream& ioStream, const Circle& circle);

private:
	Point _center;
	unsigned int _r;
};

class Rect : public Shape, public Printable
{
public:
	Rect(int x, int y, unsigned int length, unsigned int width) : _center(x,y), _length(length), _width(width), Printable("Rectangle") { ++count; };
	Rect(Point center, unsigned int length, unsigned int width) : _center(center), _length(length), _width(width), Printable("Rectangle") { ++count; };

	std::string print() const
	{
		std::stringstream tmp;
		tmp << this->getName() << " X=" << _center.getX() << " Y=" << _center.getY() << " Length=" << _length << " Width=" << _width;

		return std::string(tmp.str());
	}


	friend std::ostream& operator<< (std::ostream& ioStream, const Rect& point);
private:
	Point _center;
	unsigned int _length, _width;
};

class Polyline : public Shape, public Printable
{
public:
	Polyline(int x, int y) : _points(Point(x, y)), Printable("Polyline") { ++count; };
	Polyline(Point point) : _points(point), Printable("Polyline") { ++count; };

	std::string print() const
	{
		std::stringstream tmp;
		tmp << this->getName();

		int i = 1;
		for (XList<Point>::iterator it(_points.begin()); it != _points.end(); ++it)
		{
			tmp << " Point " << i << " " << (*it).print();
		}

		return std::string(tmp.str());
	}

	void addPoint(const int x, const int y)
	{
		_points.addTail(Point(x, y));
	}
	void addPoint(const Point& point)
	{
		_points.addTail(point);
	}

	friend std::ostream& operator<< (std::ostream& ioStream, const Polyline& point);
private:
	XList<Point> _points;
};

class Polygon : public Polyline
{
public:
	Polygon(int x, int y) : Polyline(x, y) { setName("Polygon"); };

	friend std::ostream & operator<< (std::ostream & ioStream, const Polygon& point);
};

unsigned int Shape::count = 0;

std::string Named::getName() const
{
	return _name;
}

void Named::setName(std::string name)
{
	_name = name;
}

std::ostream & operator<< (std::ostream &ioStream, const Point& point)
{
	ioStream << point.print();

	return ioStream;
}

std::ostream & operator<< (std::ostream & ioStream, const Circle& circle)
{
	ioStream << circle.print();

	return ioStream;
}

std::ostream & operator<< (std::ostream & ioStream, const Rect& rect)
{
	ioStream << rect.print();

	return ioStream;
}

std::ostream & operator<< (std::ostream & ioStream, const Polyline& polyline)
{
	ioStream << polyline.print();

	return ioStream;
}

std::ostream & operator<< (std::ostream & ioStream, const Polygon& polygon)
{
	ioStream << polygon.print();

	return ioStream;
}