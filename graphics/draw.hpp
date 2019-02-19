/* ********** Definition of drawing any object on screen ********** */

#ifndef DRAW_H
#define DRAW_H

#include "frame_buffer.h"
#include <iostream>
#include <list>
#include <math.h>
using namespace std;

#define PI 3.14159265

typedef struct{
    double x, y;
} point;

typedef struct{
    double width, length, height;
    double degree; // range between 0-360. North is 0
} cube;

// Drawing line from point p to point q with given color c
void drawLine(point p, point q, color* c);

// drawing a picture by given dots from drawPoint
// and draw it relatively from given center point
void drawPicture (list<point> drawPoint, point center, color c);

// drawing a picture by given dots from drawPoint
// and draw it relatively from given center point
void drawPictureNoFill (list<point> drawPoint, point center, color c);

// drawing a cube at given center given width, length and height
// cube will be seen rotate at given degree to right
void drawCube(point center, cube data, list<color> colors);

// checked if on given (x,y) position there is color or not
bool isColored(unsigned short x, unsigned short y);

// give the plane a given color
void rasterObject(list<point>& ctPoints, color* c);

void fillObject(point center, color* c);


#endif

