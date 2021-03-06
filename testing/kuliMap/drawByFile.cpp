#include "../../graphics/draw.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

list<point> drawPoint;

void loadDrawMap(string filename);

int main(int argc, char const *argv[])
{
	/* code */
	init();
	color black = {0,0,0,0};
	color white = {255,255,255,0};
	set_background(&black);

	point
		topRight = {1, 603},
		topLeft = {1, 1},
		bottomRight = {490, 603},
		bottomLeft = {490, 1};

	drawLine(topRight, topLeft, &white);
	drawLine(topLeft, bottomLeft, &white);
	drawLine(bottomLeft, bottomRight, &white);
	drawLine(bottomRight, topRight, &white);

	color red = {255,0,0,0};
	point left={1, 0}, right{490, 0};
	// 1 help line
	left.y = 120; right.y = 120;
	drawLine(left, right, &red);

	// 2 help line
	left.y = 240; right.y = 240;
	drawLine(left, right, &red);

	// 3 help line
	left.y = 360; right.y = 360;
	drawLine(left, right, &red);

	// 4 help line
	left.y = 450; right.y = 450;
	drawLine(left, right, &red);

	// filename relative from compiler
	loadDrawMap("sample.txt");
	
	close_buffer();
	return 0;
}

void loadDrawMap(string filename)
{
	ifstream imageFile;
	imageFile.open(filename, ios::in);
	if (imageFile.is_open())
	{
		point now;
		color c;
		int temp_r, temp_g, temp_b, temp_a;
		point center = {0, 0};
		do {
			drawPoint.clear();

			char temp;
			imageFile >> temp;
			if (temp == '#') {
				imageFile >> temp;
				// cout << temp;
				while (temp != '#') {
					imageFile >> temp;
				}
			}

			imageFile >> temp_r >> temp_g >> temp_b >> temp_a;

			// cout << temp_r << temp_g << temp_b << temp_a;
			c.r = (unsigned char) temp_r;
			c.g = (unsigned char) temp_g;
			c.b = (unsigned char) temp_b;
			c.a = (unsigned char) temp_a;
			do {
				// read new point
				imageFile >> now.x >> now.y;

				// adding point
				if (now.x != 9999 && now.x != 99999) {
					now.x += 3; now.y += 3;
					drawPoint.push_back(now);
					// cout << now.x << " " << now.y << endl;
				}
			} while (now.x != 9999 && now.x != 99999);

			drawPictureNoFill(drawPoint, center, c);
		} while (now.x != 99999);
		
		imageFile.close();
	}
	else cout << "Unable to open file";
}