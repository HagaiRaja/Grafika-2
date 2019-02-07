#include "head.h"

Head::Head()
{
	dx = 1;
}

Head::Head(point _center, color _colour, double _dx, double _dy) : Object (_center, _colour)
{
	dx = _dx;
    dy = _dy;
}

// update position
void Head::update()
{
	point new_center = this->getCenter();
	new_center.x += dx;
    new_center.y += dy;
	this->setCenter(new_center);
}

// draw the object at given center
void Head::draw()
{
	this->update();

	// draw the shape using line. On this example we draw rectangle
	drawPicture("object/airplane_parts/head/HeadPoint.txt", this->getCenter(), this->getColor());
}


/* Setter and Getter */
double Head::getDx() const
{
	return dx;
}

void Head::setDx(double i)
{
	dx = i;
}

double Body::getDy() const
{
	return dy;
}

void Body::setDy(double j)
{
	dy = j;
}
