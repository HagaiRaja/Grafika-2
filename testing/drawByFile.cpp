#include "../draw.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// drawing a picture by given dots and color from filename
// and draw it relatively from given center point
// for file specs open sample.txt
void drawPicture (string filename, point center);

int main(int argc, char const *argv[])
{
	/* code */
	init();
	color black = {0,0,0,0};
	set_background(&black);

	point center = {300, 300};
	// filename relative from compiler
	drawPicture("testing/sample.txt", center);
	

	close_buffer();
	return 0;
}

// drawing a picture by given dots and color from filename
// and draw it relatively from given center point
// for file specs open sample.txt
void drawPicture (string filename, point center) 
{
	string line;
	ifstream imageFile;
	imageFile.open(filename, ios::in);
	if (imageFile.is_open())
	{
		int r,g,b,a;

		imageFile >> r >> g >> b >> a;
		color c = {(unsigned char) r, (unsigned char) g, (unsigned char) b, (unsigned char) a};
		// cout << r << " " << g << " " << b << " " << a << endl;
		double dx, dy;
		point now, prev, first;
		// first point
		imageFile >> dx >> dy;
		now.x = center.x + dx;
		now.y = center.y + dy;
		first = now;
		do {
			// read new point
			imageFile >> dx >> dy;

			// draw line
			if (dx == 9999) {
				// end of line
				drawLine(now, first, &c);
			}
			else {
				// updating point
				prev = now;	
				now.x = center.x + dx;
				now.y = center.y + dy;
				drawLine(prev, now, &c);
			}
		} while (dx != 9999);
		

		imageFile.close();
	}
	else cout << "Unable to open file"; 
}