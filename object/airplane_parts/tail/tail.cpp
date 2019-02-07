#include "tail.h"

Tail::Tail()
{
	dx = 1;
}

Tail::Tail(point _center, color _colour, double _dx, double _dy) : Object (_center, _colour)
{
	dx = _dx;
    dy = _dy;
}

// update position
void Tail::update()
{
	point new_center = this->getCenter();
	new_center.x += dx;
    new_center.y += dy;
	this->setCenter(new_center);
}

// draw the object at given center
void Tail::draw()
{
	this->update();

	// draw the shape using line. On this example we draw rectangle
	drawPicture("object/airplane_parts/tail/TailPoint.txt", this->getCenter(), this->getColor());
}


/* Setter and Getter */
double Tail::getDx() const
{
	return dx;
}

void Tail::setDx(double i)
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
