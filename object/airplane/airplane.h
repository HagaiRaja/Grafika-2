#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "../object.h"

/* A class to draw in screen */
class Airplane : public Object {
public :
	Airplane();
	Airplane(point _center, color _colour, double _dx);

	// update position
    void update();
    // draw the object at given center
    void draw();

	/* Setter and Getter */
	double getDx() const;
	void setDx(double i);

private :
	// x and y velocity of the sample object
	double dx;
};

#endif
