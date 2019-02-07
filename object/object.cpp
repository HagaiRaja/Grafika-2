#include "object.h"

// ctor and dtor
Object::Object()
{
	point temp = {0,0};
	color white = {255,255,255,0};
	center = temp;
	colour = white;
}

Object::Object(point p, color c, string filename)
{
	center = p;
	colour = c;
	this->loadDrawPoint(filename);
}

void Object::loadDrawPoint(string filename) 
{
	ifstream imageFile;
	imageFile.open(filename, ios::in);
	if (imageFile.is_open())
	{
		point now;

		do {
			// read new point
			imageFile >> now.x >> now.y;

			// adding point
			if (now.x != 9999) {
				drawPoint.push_back(now);
			}
		} while (now.x != 9999);
		

		imageFile.close();
	}
	else cout << "Unable to open file";
}

// setter and getter
point Object::getCenter()
{
	return center;
}

void Object::setCenter(point p)
{
	center = p;
}

color Object::getColor()
{
	return colour;
}

void Object::setColor(color p)
{
	colour = p;
}

list<point> Object::getDrawPoint()
{
	return drawPoint;
}

void Object::setDrawPoint(list<point> points)
{
	drawPoint = points;
}
