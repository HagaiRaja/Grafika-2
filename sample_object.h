#ifndef SAMPLE_OBJECT_H
#define SAMPLE_OBJECT_H

#include "object.h"

/* A class to draw in screen */
class SampleObject : public Object {
public :
	SampleObject();
	SampleObject(point _center, color _colour, signed short _dx, signed short _dy);

	// update position
    void update();
    // draw the object at given center
    void draw();

	/* Setter and Getter */
	signed short getDx() const;
	void setDx(signed short i);
	signed short getDy() const;
	void setDy(signed short i);

private :
	// x and y velocity of the sample object
	signed short dx, dy;
};

#endif
