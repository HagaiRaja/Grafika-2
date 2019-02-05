#include "sample_object.h"
#include <iostream>
using namespace std;

SampleObject::SampleObject()
{
	dx = 1;
	dy = 1;
}

SampleObject::SampleObject(point _center, color _colour, double _dx, double _dy) : Object (_center, _colour)
{
	dx = _dx;
	dy = _dy;
}


// update position
void SampleObject::update()
{
	point new_center = this->getCenter();
	new_center.x += dx;
	new_center.y += dy;
	this->setCenter(new_center);
}

// draw the object at given center
void SampleObject::draw()
{
	this->update();
	// draw the shape using line. On this example we draw triangle
	point centers = this->getCenter();

	double topDotX = centers.x, topDotY = centers.y+20; 
	double leftDotX = centers.x + 15, leftDotY = centers.y;
	double rightDotX = centers.x - 15, rightDotY = centers.y;

	point 
	topDot = {topDotX, topDotY},
	leftDot = {leftDotX, leftDotY},
	rightDot = {rightDotX, rightDotY};
	
	color object_color = this->getColor();
	drawLine(topDot, leftDot, &object_color);
	drawLine(leftDot, rightDot, &object_color);
	drawLine(rightDot, topDot, &object_color);
}


/* Setter and Getter */
double SampleObject::getDx() const
{
	return dx;
}

void SampleObject::setDx(double i)
{
	dx = i;
}

double SampleObject::getDy() const
{
	return dy;
}

void SampleObject::setDy(double i)
{
	dy = i;
}
