#include "Shapes.h"

std::string Printable::getName(void) const
{
	return _name;
}

int Shape::count = 0;

int Shape::getCount(void) {
	return Shape::count;
}

std::ostream & operator<< (std::ostream &ioStream, const Point& point)
{
	ioStream << point.getName() << " X=" << point._x << " Y=" << point._y << std::endl;

	return ioStream;
}

std::ostream & operator<< (std::ostream & ioStream, const Circle& circle)
{
	ioStream << circle.getName() << " X=" << circle._x << " Y=" << circle._y << " R=" << circle._r << std::endl;

	return ioStream;
}

std::ostream & operator<< (std::ostream & ioStream, const Rect& rect)
{
	ioStream << rect.getName() << " X=" << rect._x << " Y=" << rect._y << " Length=" << rect._length << " Width=" << rect._width << std::endl;

	return ioStream;
}

std::ostream & operator<< (std::ostream & ioStream, const Polyline& polyline)
{
	ioStream << polyline.getName() << std::endl;

	return ioStream;
}

std::ostream & operator<< (std::ostream & ioStream, const Polygon& polygon)
{
	ioStream << polygon.getName() << std::endl;

	return ioStream;
}

void Polyline::addPoint(const int x, const int y)
{
	_points.addTail(Point(x,y));
}

void Polyline::addPoint(const Point & point)
{
	_points.addTail(point);
}