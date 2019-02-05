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


	point ctPoints[] = {{500,300},{400,200},{300,400},{300,300}};
	// point ctPoints[4];
	// ctPoints[0].x = 300;
	point a = {ctPoints[0].x + translateX,ctPoints[0].x+ translateY};
	point b = {ctPoints[0].x+500 + translateX,ctPoints[0].x+ translateY};
	drawLine(a, b, &blue);
	rasterObject(ctPoints, &green);


	close_buffer();
	return 0;
}
