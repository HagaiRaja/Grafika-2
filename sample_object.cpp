#include "sample_object.h"
#include <iostream>
using namespace std;

SampleObject::SampleObject()
{
	dx = 1;
	dy = 1;
}

SampleObject::SampleObject(point _center, color _colour, signed short _dx, signed short _dy) : Object (_center, _colour)
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

	int topDotX = centers.x, topDotY = centers.y+20; 
	int leftDotX = centers.x + 15, leftDotY = centers.y;
	int rightDotX = centers.x - 15, rightDotY = centers.y;

	point 
	topDot = {topDotX, topDotY},
	leftDot = {leftDotX, leftDotY},
	rightDot = {rightDotX, rightDotY};
	
	drawLine(topDot, leftDot, this->getColor());
	drawLine(leftDot, rightDot, this->getColor());
	drawLine(rightDot, topDot, this->getColor());
}


/* Setter and Getter */
signed short SampleObject::getDx() const
{
	return dx;
}

void SampleObject::setDx(signed short i)
{
	dx = i;
}

signed short SampleObject::getDy() const
{
	return dy;
}

void SampleObject::setDy(signed short i)
{
	dy = i;
}
