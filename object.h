#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "draw.h"

class Object {
	public :
	// ctor and dtor
	Object();
	Object(point p, color *c);
	Object(point& p, color& c);
	// update position
    void update();
    // draw the object at given center
    void draw();

    // setter and getter
    point getCenter();
    void setCenter(point p);
    color* getColor();
    void setColor(color* p);

    private :
    point center;
    color *colour;
};

#endif