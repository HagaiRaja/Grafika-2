#ifndef CANON_H
#define CANON_H

#include "../object.h"

/* A class to draw in screen */
class Canon : public Object {
public :
	Canon();
	Canon(point _center, color _colour);

	// update position
    void update();
    // draw the object at given center
    void draw();

	/* Setter and Getter */
	double getDegree() const;
	void setDegree(double i);

private :
	// 0 means to top
	double degree;
};

#endif
