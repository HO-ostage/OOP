#include "Factory.h"
#include <cstdlib>

Point * Factory::createPoint()
{
	return new Point(rand() % 200 - 100, rand() % 200 - 100);
}

Circle * Factory::createCircle()
{
	return new Circle(rand() % 200 - 100, rand() % 200 - 100, rand() % 200);
}

Rect * Factory::createRect()
{
	return new Rect(rand() % 200 - 100, rand() % 200 - 100, rand() % 200, rand() % 200);
}

Polyline * Factory::createPolyline()
{
	Polyline * tmp = new Polyline(rand() % 200 - 100, rand() % 200 - 100);
	int num = rand() % 10 + 1;

	for (int i = 0; i < num; ++i)
		tmp->addPoint(rand() % 200 - 100, rand() % 200 - 100);
	return tmp;
}

Polygon * Factory::createPolygon()
{
	Polygon * tmp = new Polygon(rand() % 200 - 100, rand() % 200 - 100);
	int num = rand() % 10 + 1;

	for (int i = 0; i < num; ++i)
		tmp->addPoint(rand() % 200 - 100, rand() % 200 - 100);
	return tmp;
}