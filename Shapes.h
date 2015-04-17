#pragma once

#include "Base.h"
#include "XList.cpp"
#include <iostream>

class Shape : virtual public Named
{
public:
	static int getCount(void);
	virtual ~Shape() = 0 {}
protected:
	static int count;
};

class Point : public Printable, public Shape
{
public:
	Point() : _x(0), _y(0), Printable("Point") { ++count; };
	Point(int x, int y) : _x(x), _y(y), Printable("Point") { ++count; };

	~Point() { --count; }

	friend std::ostream & operator<< (std::ostream & ioStream, const Point& point);

private:
	int _x, _y;
};

class Circle : public Shape, public Printable
{
public:
	Circle() : _x(0), _y(0), _r(1), Printable("Circle") { ++count; };
	Circle(int x, int y, int r) : _x(x), _y(y), _r(r), Printable("Circle") { ++count; };

	~Circle() { --count; };

	friend std::ostream & operator<< (std::ostream & ioStream, const Circle& circle);

private:
	int _x, _y, _r;

};

class Rect : public Shape, public Printable
{
public:
	Rect() : _x(0), _y(0), Printable("Rectangle") { ++count; };
	Rect(int x, int y, int length, int width) : _x(x), _y(y), _length(length), _width(width), Printable("Rectangle") { ++count; };

	~Rect() { --count; };

	friend std::ostream & operator<< (std::ostream & ioStream, const Rect& point);

private:
	int _x, _y, _length, _width;
};

class Polyline : public Shape, public Printable
{
public:
	Polyline() : _points(Point()), Printable("Polyline") { ++count; };
	Polyline(int x, int y) : _points(Point(x, y)), Printable("Polyline") { ++count; };

	~Polyline() { --count; };

	void addPoint(const int x, const int y);
	void addPoint(const Point & point);

	friend std::ostream & operator<< (std::ostream & ioStream, const Polyline& point);

private:
	XList<Point> _points;
};

class Polygon : public Polyline
{
public:
	Polygon() : Polyline() { _name = "Polygon"; }
	Polygon(int x, int y) : Polyline(x, y) { _name = "Polygon"; }

	friend std::ostream & operator<< (std::ostream & ioStream, const Polygon& point);
};
