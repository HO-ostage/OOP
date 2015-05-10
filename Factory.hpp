#include "Shapes.hpp"
#include <cstdlib>

class Factory
{
public:
	Point * createPoint() const {
		return new Point(rand() % 200 - 100, rand() % 200 - 100);
	}

	Circle * createCircle() const {
		return new Circle(rand() % 200 - 100, rand() % 200 - 100, rand() % 200);
	}
	
	Rect * createRect() const {
		return new Rect(rand() % 200 - 100, rand() % 200 - 100, rand() % 200, rand() % 200);
	}
	
	Polyline * createPolyline() const
	{
		Polyline * tmp = new Polyline(rand() % 200 - 100, rand() % 200 - 100);
		int num = rand() % 10 + 1;

		for (int i = 0; i < num; ++i)
			tmp->addPoint(rand() % 200 - 100, rand() % 200 - 100);

		return tmp;
	}
	
	Polygon * createPolygon() const
	{
		Polygon * tmp = new Polygon(rand() % 200 - 100, rand() % 200 - 100);
		int num = rand() % 10 + 1;

		for (int i = 0; i < num; ++i)
			tmp->addPoint(rand() % 200 - 100, rand() % 200 - 100);
		return tmp;
	}
};
