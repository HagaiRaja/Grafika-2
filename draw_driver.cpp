#include "draw.hpp"
#include <list>
using namespace std;

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

	list<point> ctPoints;
	point a = {200,200};
	point b = {160,80};
	point c = {80,80};
	point d = {40,200};

	ctPoints.push_front(d);
	ctPoints.push_front(c);
	ctPoints.push_front(b);
	ctPoints.push_front(a);

	point p = {60,40};
	point q = {60,20};
	point p1 = {30,50};
	point q1 = {50,50};
	// drawLine(p, q, &blue);
	// drawLine(p1, q1, &blue);

	drawLine(a,b,&green);
	drawLine(b,c,&green);
	drawLine(c,d,&green);
	drawLine(d,a,&green);

	rasterObject(ctPoints, &green);


	close_buffer();
	return 0;
}
