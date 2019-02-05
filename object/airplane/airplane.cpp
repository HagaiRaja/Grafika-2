Airplane::Airplane()
{
	dx = 1;
}

Airplane::Airplane(point _center, color _colour, double _dx) : Object (_center, _colour)
{
	dx = _dx;
}


// update position
void Airplane::update()
{
	point new_center = this->getCenter();
	new_center.x += dx;
	new_center.y += dy;
	this->setCenter(new_center);
}

// draw the object at given center
void Airplane::draw()
{

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
