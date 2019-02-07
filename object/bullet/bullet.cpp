#include "bullet.h"

Bullet::Bullet()
{
	dx = 0;
	dy = -1;
}

Bullet::Bullet(point _center, color _colour, double _dx, double _dy) : Object (_center, _colour, "object/bullet/BulletPoint.txt")
{
	dx = _dx;
	dy = _dy;
}


// update position
void Bullet::update()
{
	point new_center = this->getCenter();
	new_center.x += dx;
	new_center.y += dy;
	this->setCenter(new_center);
}

// draw the object at given center
void Bullet::draw()
{
	this->update();

	// draw the shape using line. On this example we draw rectangle
	drawPicture(this->getDrawPoint(), this->getCenter(), this->getColor());
}


/* Setter and Getter */
double Bullet::getDx() const
{
	return dx;
}

void Bullet::setDx(double i)
{
	dx = i;
}

double Bullet::getDy() const
{
	return dy;
}

void Bullet::setDy(double i)
{
	dy = i;
}
