#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "../graphics/draw.hpp"

class Object {
	public :
	// ctor and dtor
	Object();
	Object(point p, color c);
	// update position
    virtual void update() = 0;
    // draw the object at given center
    virtual void draw() = 0;

    // setter and getter
    point getCenter();
    void setCenter(point p);
    color getColor();
    void setColor(color p);

    private :
    point center;
    color colour;
};

#endif