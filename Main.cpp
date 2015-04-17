#include "Factory.h"
#include "Shapes.h"
#include <cstdlib>
#include <iostream>


int main()
{
	
	Factory * factory = new Factory();
	XList<Shape *> shapes;

	shapes.addHead(factory->createPoint());
	shapes.addTail(factory->createCircle());
	shapes.addTail(factory->createPolyline());
	shapes.addTail(factory->createPolygon());
	shapes.addTail(factory->createRect());

	for (int i = 0; i < 16; ++i)
	{
		int num = rand() % 5;
		switch (num)
		{
			case 0:
			{
				shapes.addTail(factory->createCircle());
				break;
			}
			case 1:
			{
				shapes.addTail(factory->createPolyline());
				break;
			}
			case 2:
			{
				shapes.addTail(factory->createPoint());
				break;
			}
			case 3:
			{
				shapes.addTail(factory->createRect());
				break;
			}
			case 4:
			{
				shapes.addTail(factory->createPolygon());
				break;
			}
		}
	}

	std::cout << Shape::getCount() << std::endl;

	int count = 0;

	for (XList<Shape*>::iterator it(shapes.begin()); it != shapes.end(); ++it)
	{
		
		if (Point * tmp = dynamic_cast<Point *>(*it)) {
			++count;
			std::cout << *tmp;
		}
	}
	std::cout << "There is " << count << " points" << std::endl;

	count = 0;
	for (XList<Shape*>::iterator it(shapes.begin()); it != shapes.end(); ++it)
	{
		
		if (Circle * tmp = dynamic_cast<Circle *>(*it)) {
			++count;
			std::cout << *tmp;
		}
	}
	std::cout << "There is " << count << " circles" << std::endl;

	count = 0;
	for (XList<Shape*>::iterator it(shapes.begin()); it != shapes.end(); ++it)
	{
		if (Rect * tmp = dynamic_cast<Rect *>(*it)) {
			++count;
			std::cout << *tmp;
		}
	}
	std::cout << "There is " << count << " rects" << std::endl;

	count = 0;
	for (XList<Shape*>::iterator it(shapes.begin()); it != shapes.end(); ++it)
	{
		if (Polyline * tmp = dynamic_cast<Polyline *>(*it)) {
			++count;
			std::cout << *tmp;
		}
	}
	std::cout << "There is " << count << " polylines" << std::endl;

	count = 0;
	for (XList<Shape*>::iterator it(shapes.begin()); it != shapes.end(); ++it)
	{
		if (Polygon * tmp = dynamic_cast<Polygon *>(*it)) {
			++count;
			std::cout << *tmp;
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