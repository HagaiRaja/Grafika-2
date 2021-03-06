#include "aircube.h"

Aircube::Aircube()
{
	dx = -1;
	dy = 1;
	direction = false;
}

Aircube::Aircube(point _center, list<color> _colour, cube _data) : Object (_center, _colour.front(), "object/airplane/PlanePoint.txt")
{
	dx = 4;
	dy = 0.6;
	this->setData(_data);
	this->setColors(_colour);
	direction = true;
}

// update position
void Aircube::update()
{
	point new_center = this->getCenter();
	if (new_center.x < -200 || new_center.x > 1500) {
		this->setDirection(!(this->getDirection()));
		new_center.y = 100;

		cube new_data = this->getData();
		new_data.degree *= -1;
		this->setData(new_data);

		dx *= -1;
	}
	new_center.x += dx;
	new_center.y += dy;
	this->setCenter(new_center);
	this->setDegree((this->getDegree()) + 5);
}

// draw the object at given center
void Aircube::draw()
{
	color yellow = {255,255,0};
	this->update();

	point center = this->getCenter();
	cube data = this->getData();
	drawCube(center, data, this->getColors());

	data.width /= 2;
	data.length /= 2;
	data.height /= 2;
	drawCube(center, data, this->getColors());
	drawSpin(center, this->getDegree(), yellow);

	if (this->getDirection()) {
		center.x += ((data.width*2)*11/16*((center.y*3)/SCREEN_HEIGHT));
	}
	else {
		center.x -= ((data.width*2)*11/16*((center.y*3)/SCREEN_HEIGHT));
	}
	data.width /= 2;
	data.length = data.length * 2 / 3;
	drawCube(center, data, this->getColors());
}


/* Setter and Getter */
double Aircube::getDx() const
{
	return dx;
}

void Aircube::setDx(double i)
{
	dx = i;
}

double Aircube::getDy() const
{
	return dy;
}

void Aircube::setDy(double i)
{
	dy = i;
}

cube Aircube::getData() const
{
	return data;
}

void Aircube::setData(cube i)
{
	data = i;
}

list<color> Aircube::getColors() const
{
	return colors;
}

void Aircube::setColors(list<color> i)
{
	colors = i;
}

bool Aircube::getDirection() const
{
	return direction;
}

void Aircube::setDirection(bool i)
{
	direction = i;
}

double Aircube::getDegree() const
{
	return degree;
}

void Aircube::setDegree(double i)
{
	degree = i;
}