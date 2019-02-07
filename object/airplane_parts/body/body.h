#ifndef BODY_H
#define BODY_H

#include "../object.h"

/* A class to draw in screen */
class Body : public Object {
public :
	Body();
	Body(point _center, color _colour, double _dx, double _dy);

	// update position
    void update();
    // draw the object at given center
    void draw();

	/* Setter and Getter */
	double getDx() const;
	void setDx(double i);
    double getDy() const;
	void setDy(double j);

private :
	// x and y velocity of the sample object
	double dx;
    double dy;
};

#endif
