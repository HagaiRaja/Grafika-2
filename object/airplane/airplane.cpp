#include "airplane.h"

Airplane::Airplane()
{
	dx = 1;
}

Airplane::Airplane(point _center, color _colour, double _dx) : Object (_center, _colour, "object/airplane/PlanePoint.txt")
{
	dx = _dx;
}

// update position
void Airplane::update()
{
	point new_center = this->getCenter();
	if (new_center.x < -200) {
		new_center.x = SCREEN_WIDTH + 200;
	}
	new_center.x += dx;
	this->setCenter(new_center);
}

// draw the object at given center
void Airplane::draw()
{
	this->update();

	// draw the shape using line. On this example we draw rectangle
	drawPicture(this->getDrawPoint(), this->getCenter(), this->getColor());
}


/* Setter and Getter */
double Airplane::getDx() const
{
	return dx;
}

void Airplane::setDx(double i)
{
	dx = i;
}
