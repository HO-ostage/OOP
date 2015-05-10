#include "Factory.hpp"
#include "Shapes.hpp"
#include <cstdlib>
#include <iostream>
#include <typeinfo>


int main()
{
	Factory factory;
	XList<Shape *> shapes;

	shapes.addTail(factory.createPoint());
	shapes.addTail(factory.createCircle());
	shapes.addTail(factory.createPolyline());
	shapes.addTail(factory.createPolygon());
	shapes.addTail(factory.createRect());

	for (int i = 0; i < 16; ++i)
	{
		int num = rand() % 5;
		switch (num)
		{
			case 0:
			{
				shapes.addTail(factory.createCircle());
				break;
			}
			case 1:
			{
				shapes.addTail(factory.createPolyline());
				break;
			}
			case 2:
			{
				shapes.addTail(factory.createPoint());
				break;
			}
			case 3:
			{
				shapes.addTail(factory.createRect());
				break;
			}
			case 4:
			{
				shapes.addTail(factory.createPolygon());
				break;
			}
		}
	}

	std::cout << Shape::getCount() << std::endl;

	int count = 0;

	for (XList<Shape*>::iterator it(shapes.begin()); it != shapes.end(); ++it)
	{
		
		if (typeid(*it) == typeid(Point)) {
			++count;
			std::cout << (*it);
		}
	}
	std::cout << "There is " << count << " points" << std::endl;

	count = 0;
	for (XList<Shape*>::iterator it(shapes.begin()); it != shapes.end(); ++it)
	{
		if (typeid(*it) == typeid(Circle)) {
			++count;
			std::cout << (*it);
		}
	}
	std::cout << "There is " << count << " circles" << std::endl;

	count = 0;
	for (XList<Shape*>::iterator it(shapes.begin()); it != shapes.end(); ++it)
	{
		if (typeid(*it) == typeid(Circle)) {
			++count;
			std::cout << (*it);
		}
	}
	std::cout << "There is " << count << " rects" << std::endl;

	count = 0;
	for (XList<Shape*>::iterator it(shapes.begin()); it != shapes.end(); ++it)
	{
		if (typeid(*it) == typeid(Polyline)) {
			++count;
			std::cout << (*it);
		}
	}
	std::cout << "There is " << count << " polylines" << std::endl;

	count = 0;
	for (XList<Shape*>::iterator it(shapes.begin()); it != shapes.end(); ++it)
	{
		if (typeid(*it) == typeid(Polygon)) {
			++count;
			std::cout << (*it);
		}
	}
	std::cout << "There is " << count << " polygones" << std::endl;

	for (XList<Shape*>::iterator it(shapes.begin()); it != shapes.end();)
	{
		Shape * toDel = *it;
		++it;
		delete toDel;;
	}

	shapes.clear();

	std::cout << Shape::getCount();

	return 0;
}