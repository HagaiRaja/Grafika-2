#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "../graphics/draw.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

class Object {
	public :
	// ctor and dtor
	Object();
	Object(point p, color c, string filename);
	// update position
    virtual void update() = 0;
    // draw the object at given center
    virtual void draw() = 0;
    // load object's drawPoint from given filename
    // for given file specs, look at testing/drawPicture/sample.txt file
    void loadDrawPoint(string filename);

    // setter and getter
    point getCenter();
    void setCenter(point p);
    color getColor();
    void setColor(color p);
    list<point> getDrawPoint();
    void setDrawPoint(list<point> points);

    private :
    point center;
    list<point> drawPoint;
    color colour;
};

#endif