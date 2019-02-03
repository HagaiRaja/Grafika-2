#include "draw.h"

// given a number and return the absolut value
unsigned short absolute (unsigned short a)
{
	(a > 0) ? return a : return -a; 
}

// Drawing line from point p to point q with given color c
// Implementation using bresenham algorithm
void drawLine(point p, point q, color* c) 
{
	unsigned short temp_x, temp_y;

	if (p.x > q.x) 
	{

	}
	else if (p.x == q.x) 
	{

	}
	else // (p.x < q.x) 
	{

	}
}
 
// Drawing Canon with given center point with line color c
void drawCanon(point center, color* c)
{

}

// Drawing Bullet with given center point with line color c
void drawBullet(point center, color* c)
{

}

// Drawing Plane with given center point with line color c
void drawPlane(point center, color* c)
{

}