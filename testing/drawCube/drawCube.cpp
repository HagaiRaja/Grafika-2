#include "../../graphics/draw.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

list<color> colours;

int main(int argc, char const *argv[])
{
	/* code */
	init();
	color black = {0,0,0,0};
	color white = {255,255,255,0};
	color red = {255,0,0,0};
	color green = {0,255,0,0};
	color blue = {0,0,255,0};
	set_background(&black);

	colours.push_back(red);
	colours.push_back(green);
	colours.push_back(blue);

	double center_x = 300, center_y = 300,
			length = 50, width = 200, height = 100,
			degree = 300;
	

	point center = {center_x, center_y};
	cube data = {width, length, height, degree};
	drawCube(center, data, colours);

	center = {center_x, center_y};
	data = {width/2, length/2, height/2, degree};
	drawCube(center, data, colours);

	center = {center_x - (width*11/16), center_y};
	data = {width/4, length/3, height/2, degree};
	drawCube(center, data, colours);

	center_x = 600; 
	center_y = 600;
	degree = -300;
	center = {center_x, center_y};
	data = {width, length, height, degree};
	drawCube(center, data, colours);

	center = {center_x, center_y};
	data = {width/2, length/2, height/2, degree};
	drawCube(center, data, colours);

	center = {center_x + (width*11/16), center_y};
	data = {width/4, length/3, height/2, degree};
	drawCube(center, data, colours);
	
	close_buffer();
	return 0;
}