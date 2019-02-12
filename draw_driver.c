#include "draw.h"

int main(int argc, char const *argv[])
{
	/* code */
	init();

	color black = {0,0,0,255};
	color white = {255,255,255,0};
	color red = {255,0,0,0};
	color green = {0,255,0,0};
	color blue = {0,0,255,0};
	set_background(&black);

	unsigned short translateX = 0;
	unsigned short translateY = 0;


	// point ctPoints[] = {{500,300},{400,200},{300,400},{300,300}};
	list<point> ctPoints;
	point a = {500,300}
	point b = {400,200}
	point c = {300,300}
	point d = {300,400}

	ctPoints.push_front(d);
	ctPoints.push_front(c);
	ctPoints.push_front(b);
	ctPoints.push_front(a);

	point p = {600,400};
	point q = {600,200};
	point p1 = {300,500};
	point q1 = {500,500};
	drawLine(p, q, &blue);
	drawLine(p1, q1, &blue);
	drawLine(a,b,&green);
	drawLine(b,c,&green);
	drawLine(c,d,&green);
	drawLine(d,a,&green);

	rasterObject(ctPoints, &green);


	close_buffer();
	return 0;
}
