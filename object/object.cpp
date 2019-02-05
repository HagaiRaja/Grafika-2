#include "object.h"

// ctor and dtor
Object::Object()
{
	point temp = {0,0};
	color white = {255,255,255,0};
	center = temp;
	colour = white;
}

Object::Object(point p, color c)
{
	center = p;
	colour = c;
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
