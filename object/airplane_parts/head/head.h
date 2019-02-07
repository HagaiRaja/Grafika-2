#ifndef HEAD_H
#define HEAD_H

#include "../object.h"

/* A class to draw in screen */
class Head : public Object {
public :
	Head();
	Head(point _center, color _colour, double _dx, double _dy);

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
