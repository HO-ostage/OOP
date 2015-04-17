#include "Shapes.h"

class Factory
{
public: 
	enum Figure {point, circle, rect, polyline, polygon};
	
	void * createShape(Figure type);
	
	Point * createPoint();
	Circle * createCircle();
	Rect * createRect();
	Polyline * createPolyline();
	Polygon * createPolygon();
};