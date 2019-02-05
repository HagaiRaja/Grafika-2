Canon::Canon()
{
	degree = 0;
}

Canon::Canon(point _center, color _colour) : Object (_center, _colour)
{
	degree = 0;
}

// update position
void Canon::update(double _degree)
{
	degree = _degree;
}

// draw the object at given center
void Canon::draw()
{
	
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
