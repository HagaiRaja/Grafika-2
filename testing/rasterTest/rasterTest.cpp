#include "../../graphics/draw.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

list<point> drawPoint;

void loadDrawPoint(string filename, int i);

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

	point center = {300, 300};
	// filename relative from compiler
	loadDrawPoint("sample.txt", 1);
	drawPicture(drawPoint, center, green);

	center = {700, 300};
	// filename relative from compiler
	loadDrawPoint("sample1.txt", 1);
	drawPicture(drawPoint, center, green);

	close_buffer();
	return 0;
}

void loadDrawPoint(string filename, int i)
{
	drawPoint.clear();
	ifstream imageFile;
	imageFile.open(filename, ios::in);
	if (imageFile.is_open())
	{
		point now;

		do {
			// read new point
			imageFile >> now.x >> now.y;

			// adding point
			if (now.x != 9999) {
				drawPoint.push_back(now);
			}
		} while (now.x != 9999);
		

		imageFile.close();
	}
	else cout << "Unable to open file";
}