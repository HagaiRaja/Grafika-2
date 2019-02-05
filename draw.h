/* ********** Definition of drawing any object on screen ********** */

#ifndef DRAW_H
#define DRAW_H

#include "frame_buffer.h"

typedef struct{
    unsigned short x, y;
} point;

// Drawing line from point p to point q with given color c
void drawLine(point p, point q, color* c);
 
// Drawing Canon with given center point with line color c
void drawCanon(point center, color* c);

// Drawing Bullet with given center point with line color c
void drawBullet(point center, color* c);

// Drawing Plane with given center point with line color c
void drawPlane(point center, color* c);

void rasterObject(point ctPoints[], color* c);
#endif

