/* ********** Definition of drawing any object on screen ********** */

#ifndef DRAW_H
#define DRAW_H

#include "frame_buffer.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct{
    double x, y;
} point;

// Drawing line from point p to point q with given color c
void drawLine(point p, point q, color* c);

// drawing a picture by given dots and color from filename
// and draw it relatively from given center point
// for file specs open sample.txt
void drawPicture (string filename, point center);


#endif

