#ifndef AIRCUB_H
#define AIRCUB_H

#include "../object.h"

/* A class to draw in screen */
class Aircube : public Object {
public :
	Aircube();
	Aircube(point _center, list<color> _colour, cube _data);

	// update position
    void update();
    // draw the object at given center
    void draw();

	/* Setter and Getter */
	double getDx() const;
	void setDx(double i);
	double getDy() const;
	void setDy(double i);
	cube getData() const;
	void setData(cube i);
	list<color> getColors() const;
	void setColors(list<color> i);
	bool getDirection() const;
	void setDirection(bool i);
	double getDegree() const;
	void setDegree(double i);

private :
	double dx, dy;			// x and y velocity of the sample object
	cube data;
	list<color> colors;
	bool direction; 		// true means left to right, vice versa.
	double degree;
};

#endif
