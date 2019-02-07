#include "canon.h"

Canon::Canon()
{
	degree = 0;
}

Canon::Canon(point _center, color _colour) : Object (_center, _colour, "object/canon/CanonPoint.txt")
{
	degree = 0;
}

// update position
void Canon::update()
{
	degree = 0;
}

// draw the object at given center
void Canon::draw()
{
	// draw the shape using line. On this example we draw rectangle
	drawPicture(this->getDrawPoint(), this->getCenter(), this->getColor());
}

/* Setter and Getter */
double Canon::getDegree() const
{
	return degree;
}

void Canon::setDegree(double i)
{
	degree = i;
}
