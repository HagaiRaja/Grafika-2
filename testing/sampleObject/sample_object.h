#ifndef SAMPLE_OBJECT_H
#define SAMPLE_OBJECT_H

#include "../../object/object.h"

/* A class to draw in screen */
class SampleObject : public Object {
public :
	SampleObject();
	SampleObject(point _center, color _colour, double _dx, double _dy);

	// update position
    void update();
    // draw the object at given center
    void draw();

	/* Setter and Getter */
	double getDx() const;
	void setDx(double i);
	double getDy() const;
	void setDy(double i);

private :
	// x and y velocity of the sample object
	double dx, dy;
};

#endif
